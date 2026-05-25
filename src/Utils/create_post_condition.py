from __future__ import annotations

import subprocess
import os
import re
from convertor import SpecificationConvertor


def create_post_dict_list(data:str)->list:
    # 将Input字符串按两段分割
    data_list = data.strip().split("\n\n")
    output = []
    for index, item_str in enumerate(data_list, start=1):  # 从1开始递增
        # 分割每个条目为 return_value 和 path_condition
        lines = item_str.split("\n")
        return_value = lines[0].split(": ")[1]
        path_condition = lines[1].split(": ")[1]

        # 为每个条目分配递增的 ID
        item = {
            "id": index,  # 使用递增的数字作为 id
            "return_value": return_value,
            "path_condition": path_condition
        }
        output.append(item)
    return output


def delete_file_if_exists(file_path):
    """如果文件存在，则Deleted文件"""
    # 构建完整的文件路径
    file_path = os.path.join('../QCP/test', file_path)

    if os.path.exists(file_path):  # 检查文件是否存在
        os.remove(file_path)  # Deleted文件
    

def _read_file(file_path: str) -> str:
    with open(file_path, "r", encoding="utf-8") as file:
        return file.read()


def _strip_qcp_loop_assertions(code: str) -> str:
    code = re.sub(r"/\*@\s*Print user assertion[\s\S]*?\*/\s*", "", code)
    code = re.sub(r"/\*@\s*Inv[\s\S]*?\*/\s*", "", code)
    # Strip ACSL line-comment assertions (`//@ assert ...;`) left in the body.
    # QCP only understands block annotations (`/*@ ... */`); a `//@ assert`
    # carrying arithmetic trips the bison parser (`unexpected PT_PLUS`, case
    # frama-c-loop/2, where the assert sits inside the target's loop body).
    # These are user verification goals, not inputs to postcondition
    # synthesis, so dropping them does not weaken the SE result. QCP never
    # emits `//@`, so this only ever removes ACSL leftovers.
    code = re.sub(r"^[ \t]*//@.*$\n?", "", code, flags=re.MULTILINE)
    # SE-translation hardening: strip ACSL-style /*@ loop invariant ...;
    # loop assigns ...; */ blocks too. They occasionally survive in the
    # 2_output file (written by inv_gen during the LLM-fill iteration)
    # and the QCP bison parser chokes on the `loop invariant` keyword,
    # tripping create_post's SE call (case sespec/102: PT_NATLIT at the
    # `0 <= sum` clause).
    #
    # Only match annotation blocks whose body *itself* mentions a
    # `loop invariant` / `loop assigns` / `loop variant` clause. Iterate
    # over every /*@...*/ block so we don't catch unrelated blocks
    # (predicate / logic / requires / ensures …) that just happen to
    # precede a loop annotation elsewhere in the file. A prior version
    # of this strip used a regex with a global look-ahead which
    # incorrectly dropped predicate definitions in sespec/149.
    annot_re = re.compile(r"/\*@[\s\S]*?\*/\s*")
    loop_kw_re = re.compile(r"\bloop\s+(?:invariant|assigns|variant)\b")
    out = []
    cursor = 0
    for m in annot_re.finditer(code):
        body = m.group(0)
        if loop_kw_re.search(body):
            # drop this block
            out.append(code[cursor:m.start()])
            cursor = m.end()
    out.append(code[cursor:])
    return "".join(out)


def _acsl_ptr_lengths(acsl_code: str) -> dict[str, str]:
    """Recover array lengths from ACSL `\\valid[_read](p + (lo..hi))` ranges.

    The QCP precondition built by spec_gen / convertor falls back to the
    undeclared predicate `store_int_ptr(p)` whenever its own regex length
    resolver (Utils.utils.resolve_array_lengths) cannot bind a length —
    which it cannot for `while (i < n)` array loops, since `_loop_upper_bounds`
    only scans `for` headers. The LLM-produced ACSL, however, already carries
    the resolved bound as a validity range, e.g.

        requires \\valid_read(a + (0..n-1));

    Translate those ranges into QCP element counts so the caller can rewrite
    `store_int_ptr(a)` into `store_int_array(a, n, a_l)`. Returns ptr-name →
    length-expression. Only the first range seen for a pointer is kept.
    """
    # \valid / \valid_read ( <ptr> + ( <lo> .. <hi> ) )
    # <ptr> is either a bare name `a` or an address-of-element `&a[0]`.
    rng = re.compile(
        r"\\valid(?:_read)?\s*\(\s*"
        r"(?:&\s*(\w+)\s*\[\s*0\s*\]|(\w+))"
        r"\s*\+\s*\(\s*([^.]+?)\s*\.\.\s*([^)]+?)\s*\)\s*\)"
    )
    out: dict[str, str] = {}
    for m in rng.finditer(acsl_code):
        name = m.group(1) or m.group(2)
        lo, hi = m.group(3).strip(), m.group(4).strip()
        if name in out:
            continue
        if lo == "0":
            # 0..hi  →  hi+1 elements; simplify the common `n-1` to `n`.
            base = re.fullmatch(r"(.+?)\s*-\s*1", hi)
            length = base.group(1).strip() if base else f"{hi} + 1"
        else:
            length = f"({hi}) - ({lo}) + 1"
        out[name] = length
    return out


def _rewrite_store_int_ptr_from_acsl(qcp_code: str, acsl_code: str) -> str:
    """Rewrite QCP `store_int_ptr(p)` → `store_int_array(p, <len>, p_l)` using
    lengths recovered from the ACSL validity ranges (see `_acsl_ptr_lengths`).

    `store_int_ptr` is not a declared QCP predicate, so leaving it in makes
    symexec abort with `Use of undeclared identifier 'store_int_ptr'`. We only
    rewrite a pointer when (a) the ACSL gives it a length and (b) the QCP code
    already binds its `<p>_l` ghost (always emitted alongside the predicate),
    so the rewritten `store_int_array` stays well-formed. Pointers whose ACSL
    is only a plain `\\valid(p)` (no range) keep `store_int_ptr` and still
    fail — those need a length from another source.
    """
    lengths = _acsl_ptr_lengths(acsl_code)
    for name, length in lengths.items():
        if f"{name}_l" not in qcp_code:
            continue
        store = f"store_int_array({name}, {length}, {name}_l)"
        qcp_code = re.sub(
            r"\bstore_int_ptr\s*\(\s*" + re.escape(name) + r"\s*\)",
            store,
            qcp_code,
        )
        # Without a length bound, symexec cannot derive that even `a[0]` is a
        # valid read (the array may be empty), aborting with "Cannot derive the
        # precondition of Memory Read". The body-driven length resolver emits
        # this same `len > 0 && len < 100` guard (spec_gen.py); mirror it here
        # for the ACSL-range fallback by appending it once to the `Require`.
        qcp_code = qcp_code.replace(
            f"Require {store}",
            f"Require {store} && ({length} > 0 && {length} < 100)",
            1,
        )
    return qcp_code


def _strip_qcp_unsupported_prelude(code: str) -> str:
    code = re.sub(r"^\s*#\s*include\s*<[^>]+>\s*\n", "", code, flags=re.MULTILINE)
    prototype = re.compile(
        r"^\s*(?:[A-Za-z_][A-Za-z0-9_]*\s+|struct\s+[A-Za-z_][A-Za-z0-9_]*\s+|\*\s*)+"
        r"[A-Za-z_][A-Za-z0-9_]*\s*\([^;{}]*\)\s*;\s*\n",
        flags=re.MULTILINE,
    )
    code = prototype.sub("", code)
    return _strip_qcp_labels(code)


def _strip_qcp_labels(code: str) -> str:
    """Remove standalone C label statements (`Label_a:` on its own line).

    Source programs sometimes place a label only to anchor an ACSL
    `\\at(expr, Label_a)` assertion (case sespec frama-c-loop/3). The assertion
    is stripped upstream, but the orphan label survives into the QCP input,
    where the bison parser rejects it (`unexpected PT_COLON, expecting
    PT_SEMI`). QCP supports neither `goto` nor labelled `\\at`, so a label can
    never be referenced in a QCP program — dropping it is always safe. `case`
    and `default` labels never match this pattern (a `case` label carries an
    expression before the colon; `default` is excluded explicitly)."""
    return re.sub(
        r"^[ \t]*(?!default\b)[A-Za-z_]\w*[ \t]*:[ \t]*$\n?",
        "",
        code,
        flags=re.MULTILINE,
    )


def _extract_loop_annotation_blocks(acsl_code: str) -> list[str]:
    blocks = []
    pattern = re.compile(r"/\*@[\s\S]*?\*/", re.MULTILINE)
    for match in pattern.finditer(acsl_code):
        block = match.group(0).strip()
        tail = acsl_code[match.end():]
        if "loop invariant" in block and re.match(r"\s*\b(?:for|while)\s*\(", tail):
            blocks.append(block)
    return blocks


def _insert_invariants_before_loops(code: str, qcp_invariants: list[str]) -> str:
    if not qcp_invariants:
        return code

    matches = list(re.finditer(r"\b(?:for|while)\s*\(", code))
    if not matches:
        return code

    parts = []
    cursor = 0
    for idx, match in enumerate(matches):
        if idx >= len(qcp_invariants):
            break
        parts.append(code[cursor:match.start()])
        parts.append(qcp_invariants[idx].rstrip())
        parts.append("\n")
        cursor = match.start()
    parts.append(code[cursor:])
    return _hoist_for_loop_decls("".join(parts))


def _hoist_for_loop_decls(code: str) -> str:
    """Hoist a `for`-loop's inline index declaration out of the header when an
    `Inv` block has been inserted right before it.

    QCP places the loop `Inv` *before* the loop, but `for (int i = 0; ...)`
    scopes `i` to the loop body, so an `Inv` that mentions `i` fails with
    `Use of undeclared identifier 'i'` (cases goo13/15/16). Rewriting

        /*@ Inv ... i ... */ for (int i = 0; C; S) { ... }

    into

        int i = 0;
        /*@ Inv ... i ... */ for (i = 0; C; S) { ... }

    declares `i` in the enclosing scope so the `Inv` can see it, while the
    re-init in the header keeps loop semantics identical. Only `for` headers
    directly preceded by an `Inv` are touched; `while` loops and inner loops
    without their own `Inv` are left alone."""
    pat = re.compile(
        r"(/\*@\s*Inv[\s\S]*?\*/\s*)"
        r"for\s*\(\s*(int|unsigned\s+int|long|size_t)\s+(\w+)\s*=\s*([^;]+);",
    )

    def repl(m):
        inv, ty, var, init = m.group(1), m.group(2), m.group(3), m.group(4).strip()
        return f"{ty} {var} = {init};\n{inv}for ({var} = {init};"

    return pat.sub(repl, code)


def _prepare_qcp_input(
    file_name: str,
    annotated_loop_file_path: str,
    function_info=None,
    acsl_loop_file_path: str | None = None,
) -> tuple[str, str | None]:
    input_file = os.path.join(annotated_loop_file_path, f"{file_name}.c")
    if function_info is None or acsl_loop_file_path is None:
        return input_file, None

    acsl_file = os.path.join(acsl_loop_file_path, f"{file_name}.c")
    if not os.path.exists(input_file) or not os.path.exists(acsl_file):
        return input_file, None

    acsl_code = _read_file(acsl_file)
    acsl_blocks = _extract_loop_annotation_blocks(acsl_code)
    if not acsl_blocks:
        return input_file, None

    convertor = SpecificationConvertor(function_info)
    qcp_invariants = [convertor.convert_annotations(block) for block in acsl_blocks]
    qcp_external_decls = convertor.acsl_helpers_to_qcp_externs(acsl_code)

    qcp_code = _read_file(input_file)
    qcp_code = _strip_qcp_loop_assertions(qcp_code)
    qcp_code = _strip_qcp_unsupported_prelude(qcp_code)
    qcp_code = convertor.insert_qcp_externs(qcp_code, qcp_external_decls)
    qcp_code = _insert_invariants_before_loops(qcp_code, qcp_invariants)
    # Run *after* invariants are re-inserted: `store_int_ptr` is emitted both
    # in the `Require` clause and (via convertor.create_exists_str) inside the
    # freshly inserted `Inv` block, so rewriting earlier would miss the latter.
    qcp_code = _rewrite_store_int_ptr_from_acsl(qcp_code, acsl_code)
    with open(input_file, "w", encoding="utf-8") as file:
        file.write(qcp_code)
    return input_file, None



def create_post(
    file_name: str,
    annotated_loop_file_path: str,
    conds: list,
    function_info=None,
    acsl_loop_file_path: str | None = None,
) -> list:

    output = None
    # 定义文件路径
    goal_file = f"../goal/{file_name}_goal.v"
    proof_auto_file = f"../goal/{file_name}_proof_auto.v"
    proof_manual_file = f"../goal/{file_name}_proof_manual.v"
    # annotated_loop_file_path is now an absolute path under workspace_root,
    # so use it directly (no `../../src/` prefix).
    input_file, temp_input_file = _prepare_qcp_input(
        file_name,
        annotated_loop_file_path,
        function_info=function_info,
        acsl_loop_file_path=acsl_loop_file_path,
    )
    # 检查文件是否存在，存在则Deleted
    for file_path in [goal_file, proof_auto_file, proof_manual_file]:
        delete_file_if_exists(file_path)

    # 定义命令和参数
    command = [
        "build/symexec",
        f"--goal-file={goal_file}",
        f"--proof-auto-file={proof_auto_file}",
        f"--proof-manual-file={proof_manual_file}",
        "--no-logic-path",
        f"--input-file={input_file}",
    ]
    # print(' '.join(command))

    # 运行命令，捕获Output
    try:
        result = subprocess.run(command, cwd='../QCP/test',
                                stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        
        
        output = result.stdout.split('+++++')

        output = [
            block for block in output 
            if 'return_value' in block and 'path_condition' in block
        ]


        error = result.stderr
        # print(error)
        # print(len(output))

        if 'error' in error:
            return 'SymExec Failed'
        elif len(output):
            output = output[-1].strip()
            if(output in conds):
                return 'SymExec Failed'
            else:
                conds.append(output)
        else:
            return 'SymExec Failed'
           
            
        output = create_post_dict_list(output)
    except Exception as e:
        print(f"An error occurred: {e}")
    finally:
        if temp_input_file and os.path.exists(temp_input_file):
            os.remove(temp_input_file)

    return output

def combine_post(data) -> str:
    # 提取所有 path_condition 并用 || 连接
    print('-'* 40)
    print('Path Condition and Return Value')
    for item in data:
        if not item['return_value'] == "NULL":
           
            print("path:"+ item['path_condition'])
    path_conditions = [f"({item['path_condition']})" for item in data]
    combined_post_condition = ' || '.join(path_conditions)

    # OutputResult


    print("Combined path condition:")
    print(combined_post_condition)
    print('-'* 40+'\n')
    return combined_post_condition

def update_annotation(annotation:str, combined_post_condition:list)->str:
    ensure_part = combine_post(combined_post_condition)
    def refine_ensure(text):
        """
        Replaces every '( var1 == var2 ) * (*var2 == var3)' 
        (where var3 can now be a variable or a numeric literal)
        with '( var1 == var2 ) * (*var1 == var3)'.
        """

        # var1 可以带 '->'，var2 仅限简单标识符
        FLEXIBLE_VAR = r'(?:[A-Za-z_]\w*)(?:->(?:[A-Za-z_]\w*))*'
        SIMPLE_VAR   = r'[A-Za-z_]\w*'
        # 新增：匹配整数或小数
        LITERAL      = r'\d+(?:\.\d+)?'
        # var3 可以是 链式标识+或数字
        VAR3         = f'(?:{SIMPLE_VAR}|{LITERAL})'

        pattern = re.compile(r'''
            # 前半段： "( var1 == var2 ) * (*"
            (\(\s*
                (?P<var1>''' + FLEXIBLE_VAR + r''')   # 捕获 var1
                \s*==\s*
                (?P<var2>''' + SIMPLE_VAR   + r''')   # 捕获 var2
            \s*\)\s*\*\s*\(\*\s*)

            (?P=var2)                              # 重用 var2

            # 后半段： " == var3 )"
            (?P<suffix>
                \s*==\s*
                (?P<var3>''' + VAR3         + r''') # 捕获 var3（变量或字面量）
            \s*\)
            )
        ''', re.VERBOSE)

        replacement = r'\1\g<var1>\g<suffix>'

        return pattern.sub(replacement, text)

    ensure_part = refine_ensure(ensure_part)
    part = annotation.split('Ensure')[0].strip()
    return f'{part}\nEnsure {ensure_part}\n*/'
