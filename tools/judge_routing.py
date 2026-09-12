import re

from tree_sitter import Language, Parser
import tree_sitter_c

from check_preconditions import annotation_body, c_function_declarator

ROUTING_VERSION = 'target_annotations_literal_true_v1'
LEXICAL = re.compile(r'/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\])*"|\x27(?:\\.|[^\x27\\])*\x27', re.S)
CONTRACT_CLAUSE = re.compile(r'(?<![\w\\])(?:requires(?:_redundantly)?|ensures(?:_redundantly)?)\b')
JAVA_CONTRACT_CLAUSE = re.compile(r'(?<![\w\\])(?:requires(?:_redundantly)?|ensures(?:_redundantly)?|pre|post)\b')
INVARIANT_CLAUSE = re.compile(r'(?<![\w\\])(?:loop\s+invariant|loop_invariant|maintaining)(?:_redundantly)?\b')


def _walk(node):
    yield node
    for child in node.children:
        yield from _walk(child)


def _preceding_c_comments(node, data):
    out = []
    previous = node.prev_sibling
    while previous is not None and previous.type == 'comment':
        body = annotation_body(data[previous.start_byte:previous.end_byte].decode())
        if body is not None:
            out.insert(0, body)
        previous = previous.prev_sibling
    return out


def _c_annotations(source, target):
    data = source.encode()
    tree = Parser(Language(tree_sitter_c.language())).parse(data)
    candidates = []
    for node in _walk(tree.root_node):
        if node.type not in {'function_definition', 'declaration'}:
            continue
        fd = c_function_declarator(node.child_by_field_name('declarator'))
        if fd is None:
            continue
        name = fd.child_by_field_name('declarator')
        if name is not None:
            candidates.append((data[name.start_byte:name.end_byte].decode(), node))
    if target is None:
        names = {name for name, node in candidates if node.type == 'function_definition'}
        if len(names) != 1:
            raise ValueError('An explicit C target name is required')
        target = names.pop()
    selected = [node for name, node in candidates if name == target]
    definitions = [node for node in selected if node.type == 'function_definition']
    if len(definitions) != 1:
        raise ValueError('C target definition is missing or ambiguous: ' + target)
    contracts = [text for node in selected for text in _preceding_c_comments(node, data)]
    body = definitions[0].child_by_field_name('body')
    annotations = [annotation_body(data[n.start_byte:n.end_byte].decode())
                   for n in _walk(body) if n.type == 'comment']
    fd = c_function_declarator(definitions[0].child_by_field_name('declarator'))
    params = fd.child_by_field_name('parameters').named_children
    arity = sum(data[n.start_byte:n.end_byte].decode().strip() != 'void' for n in params)
    return contracts, [a for a in annotations if a is not None], arity


def _java_annotations(source, target, expected_arity=None):
    tokens = list(LEXICAL.finditer(source))
    masked = LEXICAL.sub(lambda m: ''.join('\n' if c == '\n' else ' ' for c in m[0]), source)
    name_pattern = re.escape(target) if target else r'[A-Za-z_$][\w$]*'
    pattern = re.compile(r'\b(' + name_pattern + r')\s*\([^()]*\)\s*(?:throws\s+[\w.,\s]+)?\{')
    matches = []
    for match in pattern.finditer(masked):
        header = re.search(r'(?:(?:public|private|protected|static|final|synchronized|native|strictfp|default)\s+)*(?:[\w.$<>?]+(?:\s*\[\])*)\s*$', masked[:match.start()])
        if header and match[1] not in {'if', 'for', 'while', 'switch', 'catch', 'synchronized'}:
            matches.append((match, header.start()))
    def arity(match):
        params = match[0][match[0].index('(') + 1:match[0].index(')')].strip()
        return 0 if not params else len(params.split(','))
    if len(matches) > 1 and expected_arity is not None:
        matches = [(match, start) for match, start in matches if arity(match) == expected_arity]
    if len(matches) != 1:
        raise ValueError('Java target declaration is missing or ambiguous: ' + str(target))
    method, start = matches[0]
    contracts = []
    for token in reversed(tokens):
        if token.end() > start:
            continue
        if source[token.end():start].strip():
            break
        body = annotation_body(token[0])
        if body is not None:
            contracts.insert(0, body)
        start = token.start()
    body_start = method.end() - 1
    depth = 1
    end = body_start + 1
    while end < len(masked) and depth:
        depth += (masked[end] == '{') - (masked[end] == '}')
        end += 1
    if depth:
        raise ValueError('Unclosed Java target body')
    annotations = [annotation_body(t[0]) for t in tokens if body_start < t.start() < end]
    return contracts, [a for a in annotations if a is not None], arity(method)


def _literal_true(remainder):
    expr, delimiter, _ = remainder.partition(';')
    if not delimiter:
        return False
    expr = re.sub(r'\s+', '', expr)
    while expr.startswith('(') and expr.endswith(')'):
        expr = expr[1:-1]
    return expr in {'true', r'\true'}


def _count(bodies, pattern):
    total = nontrivial = 0
    for body in bodies:
        for match in pattern.finditer(body):
            total += 1
            nontrivial += not _literal_true(body[match.end():])
    return total, nontrivial


def inspect_spec(source, language, target=None, expected_arity=None):
    contracts, body, arity = (_java_annotations(source, target, expected_arity) if language == 'java'
                              else _c_annotations(source, target))
    clauses, substantive = _count(contracts, JAVA_CONTRACT_CLAUSE if language == 'java' else CONTRACT_CLAUSE)
    invariants, substantive_invariants = _count(body, INVARIANT_CLAUSE)
    return dict(parameter_count=arity, contract_clause_count=clauses, nontrivial_contract_clause_count=substantive,
                invariant_count=invariants, nontrivial_invariant_count=substantive_invariants)


def route_pair(spec_a, spec_b, lang_a, target_a=None, target_b=None):
    b = inspect_spec(spec_b, 'c', target_b)
    a = inspect_spec(spec_a, lang_a, target_a, expected_arity=b['parameter_count'])
    basis = ('loop_invariants' if not (a['nontrivial_contract_clause_count'] or b['nontrivial_contract_clause_count'])
             and (a['nontrivial_invariant_count'] or b['nontrivial_invariant_count']) else 'contract')
    return dict(comparison_basis=basis, A=a, B=b)
