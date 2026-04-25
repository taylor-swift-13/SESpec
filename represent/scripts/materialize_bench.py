from __future__ import annotations

import argparse
import json
import re
import shutil
import subprocess
from pathlib import Path

from represent.api.config import get_settings
from represent.runners.common import ROOT, ensure_dirs, write_mapping


JAVA_FILE_COMMENT_RE = re.compile(r"/\*@.*?\*/", re.DOTALL)
JML_LINE_RE = re.compile(r"^\s*//@.*$", re.MULTILINE)
BLOCK_COMMENT_RE = re.compile(r"/\*.*?\*/", re.DOTALL)
LINE_COMMENT_RE = re.compile(r"^\s*//.*$", re.MULTILINE)
METHOD_RE = re.compile(
    r"(?m)^[ \t]*(?P<prefix>(?:public|private|protected)\s+)?(?P<static>static\s+)?(?P<rtype>[\w\[\]]+)\s+"
    r"(?P<name>\w+)\s*\((?P<params>[^)]*)\)\s*(?:throws [^{]+)?\{"
)
C_FUNC_RE = re.compile(
    r"(?m)^[ \t]*(?:int|void|char|float|double|long|short|unsigned|signed)\s+([A-Za-z_][A-Za-z0-9_]*)\s*\([^;{]*\)\s*\{"
)


def strip_annotations(text: str) -> str:
    return JML_LINE_RE.sub("", JAVA_FILE_COMMENT_RE.sub("", text))


def strip_all_comments(text: str) -> str:
    text = BLOCK_COMMENT_RE.sub("", text)
    text = LINE_COMMENT_RE.sub("", text)
    lines = [line.rstrip() for line in text.splitlines()]
    cleaned: list[str] = []
    previous_blank = False
    for line in lines:
        blank = not line.strip()
        if blank and previous_blank:
            continue
        cleaned.append(line)
        previous_blank = blank
    return "\n".join(cleaned).strip() + "\n"


def primitive_type(java_type: str) -> str | None:
    mapping = {
        "int": "int",
        "short": "short",
        "boolean": "int",
        "char": "char",
        "long": "long long",
        "double": "double",
        "float": "float",
        "void": "void",
        "String": "const char *",
    }
    if java_type in mapping:
        return mapping[java_type]
    if java_type.endswith("[]"):
        base = primitive_type(java_type[:-2])
        if base:
            return f"{base} *"
    if java_type.endswith("[][]"):
        base = primitive_type(java_type[:-4])
        if base:
            return f"{base} **"
    return None


def translate_params(params: str) -> tuple[str, dict[str, str], bool]:
    translated = []
    kinds: dict[str, str] = {}
    if not params.strip():
        return "", kinds, True
    ok = True
    for raw in [part.strip() for part in params.split(",") if part.strip()]:
        pieces = raw.split()
        if len(pieces) < 2:
            ok = False
            continue
        java_type = "".join(pieces[:-1])
        name = pieces[-1]
        c_type = primitive_type(java_type)
        kinds[name] = java_type
        if c_type is None:
            ok = False
            translated.append(f"/* unsupported {raw} */ int {name}")
            continue
        translated.append(f"{c_type} {name}")
        if java_type.endswith("[]"):
            translated.append(f"int {name}_len")
        if java_type.endswith("[][]"):
            translated.append(f"int {name}_rows")
            translated.append(f"int {name}_cols")
    return ", ".join(translated), kinds, ok


def normalize_local_declarations(text: str) -> tuple[str, dict[str, str], set[str]]:
    local_arrays: dict[str, str] = {}
    local_scalars: set[str] = set()

    def repl_array_decl(match: re.Match[str]) -> str:
        base = match.group("base")
        name = match.group("name1") or match.group("name2")
        size = (match.group("size") or "0").strip()
        local_arrays[name] = f"{base}[]"
        c_base = primitive_type(base) or "int"
        init = "NULL" if size == "0" else f"({c_base} *)malloc(sizeof({c_base}) * ({size}))"
        return f"{c_base} *{name} = {init};\nint {name}_len = {size};"

    array_decl = re.compile(
        r"\b(?P<base>int|char|boolean|float|double|long)\s*(?:\[\]\s*(?P<name1>\w+)|(?P<name2>\w+)\s*\[\])"
        r"\s*(?:=\s*new\s+(?P=base)\s*\[(?P<size>[^\]]+)\])?\s*;"
    )
    text = array_decl.sub(repl_array_decl, text)

    scalar_decl = re.compile(r"\bboolean\s+(\w+)\s*=")
    for match in scalar_decl.finditer(text):
        local_scalars.add(match.group(1))
    text = scalar_decl.sub(r"int \1 =", text)
    text = re.sub(r"\bboolean\s+(\w+)\s*;", r"int \1 = 0;", text)

    for base in ["int", "char", "float", "double", "long", "boolean"]:
        c_base = primitive_type(base) or "int"
        for name, size in re.findall(rf"\b(\w+)\s*=\s*new\s+{base}\s*\[([^\]]+)\]\s*;", text):
            local_arrays.setdefault(name, f"{base}[]")
            text = re.sub(
                rf"\b{name}\s*=\s*new\s+{base}\s*\[([^\]]+)\]\s*;",
                f"{name} = ({c_base} *)malloc(sizeof({c_base}) * (\\1)); {name}_len = \\1;",
                text,
            )

    text = re.sub(r"System\.out\.println\([^;]*\);", "", text)
    text = re.sub(r"\bthis\.", "", text)
    return text, local_arrays, local_scalars


def split_args(args: str) -> list[str]:
    parts: list[str] = []
    current: list[str] = []
    depth = 0
    for ch in args:
        if ch == "," and depth == 0:
            part = "".join(current).strip()
            if part:
                parts.append(part)
            current = []
            continue
        if ch in "([{":
            depth += 1
        elif ch in ")]}":
            depth -= 1
        current.append(ch)
    tail = "".join(current).strip()
    if tail:
        parts.append(tail)
    return parts


def adapt_method_calls(body: str, method_param_orders: dict[str, list[tuple[str, str]]]) -> str:
    for method_name, params in method_param_orders.items():
        array_param_positions = [(idx, kind) for idx, (name, kind) in enumerate(params) if kind.endswith("[]")]
        if not array_param_positions:
            continue
        pattern = re.compile(rf"\b{re.escape(method_name)}\s*\(([^()]*)\)")

        def repl(match: re.Match[str]) -> str:
            raw_args = match.group(1)
            args = split_args(raw_args)
            if len(args) != len(params):
                return match.group(0)
            expanded: list[str] = []
            for idx, arg in enumerate(args):
                expanded.append(arg)
                kind = params[idx][1]
                ident = arg.strip()
                if not re.fullmatch(r"[A-Za-z_]\w*", ident):
                    continue
                if kind.endswith("[][]"):
                    expanded.append(f"{ident}_rows")
                    expanded.append(f"{ident}_cols")
                elif kind.endswith("[]"):
                    expanded.append(f"{ident}_len")
            return f"{method_name}({', '.join(expanded)})"

        body = pattern.sub(repl, body)
    return body


def replace_body(body: str, param_kinds: dict[str, str], return_type: str) -> tuple[str, set[str], bool]:
    includes: set[str] = set()
    ok = True
    text = body
    text = re.sub(r"\bfinal\s+", "", text)
    text = text.replace("true", "1").replace("false", "0").replace("null", "NULL")
    text, local_arrays, _ = normalize_local_declarations(text)
    if "malloc(" in text:
        includes.add("#include <stdlib.h>")
    if "NULL" in text:
        includes.add("#include <stddef.h>")
    all_kinds = dict(param_kinds)
    all_kinds.update(local_arrays)
    for name, kind in all_kinds.items():
        if kind.endswith("[]"):
            text = re.sub(rf"\b{name}\.length\b", f"{name}_len", text)
            text = re.sub(rf"\b{name}\.length\(\)", f"{name}_len", text)
        elif kind == "String":
            text = re.sub(rf"\b{name}\.length\(\)", f"((int)strlen({name}))", text)
            text = text.replace(f"{name}.charAt(", f"{name}[")
            includes.add("#include <string.h>")
    text = re.sub(
        r"System\.arraycopy\((\w+),\s*0,\s*(\w+),\s*0,\s*(\w+)\);",
        r"for (int __i = 0; __i < \3; ++__i) { \2[__i] = \1[__i]; }",
        text,
    )
    text = re.sub(
        r"new\s+int\[(.+?)\]",
        r"(int *)malloc(sizeof(int) * (\1))",
        text,
    )
    text = re.sub(
        r"new\s+char\[(.+?)\]",
        r"(char *)malloc(sizeof(char) * (\1))",
        text,
    )
    text = re.sub(
        r"new\s+boolean\[(.+?)\]",
        r"(int *)malloc(sizeof(int) * (\1))",
        text,
    )
    text = re.sub(r"return\s+new\s+int\s*\[\s*\]\s*\{([^}]*)\}\s*;", "return 0;", text)
    text = re.sub(r"return\s+new\s+char\s*\[\s*\]\s*\{([^}]*)\}\s*;", "return 0;", text)
    if "StringBuffer" in text or "StringBuilder" in text or "regionMatches(" in text:
        ok = False
    if re.search(r"\b[A-Z]\w*\s+\w+\s*=", text):
        ok = False
    if re.search(r"\b[A-Z]\w*\[\]", text):
        ok = False
    if re.search(r"new\s+[A-Z]\w*\[", text):
        ok = False
    if re.search(r"\b[A-Z]\w*\s*\[\s*\]\s+\w+", text):
        ok = False
    if re.search(r"\b[a-zA-Z_]\w*\s*\[\s*\]\s+\w+", text) and not re.search(r"\bint\s*\[\s*\]\s+\w+|\bchar\s*\[\s*\]\s+\w+", text):
        ok = False
    if re.search(r"new\s+(?!int\b|char\b|float\b|double\b|long\b|boolean\b)[a-zA-Z_]\w*\s*\[", text):
        ok = False
    if return_type.endswith("[]"):
        ok = False
    if re.search(r"\bnew\s+[A-Za-z_]\w*", text):
        ok = False
    if re.search(r"\b[A-Za-z_]\w*\.\w+\(", text):
        ok = False
    return text, includes, ok


def find_matching_brace(text: str, open_index: int) -> int:
    depth = 0
    for idx in range(open_index, len(text)):
        if text[idx] == "{":
            depth += 1
        elif text[idx] == "}":
            depth -= 1
            if depth == 0:
                return idx
    return -1


def collect_methods(text: str) -> list[dict[str, object]]:
    methods: list[dict[str, object]] = []
    for match in METHOD_RE.finditer(text):
        open_brace = match.end() - 1
        close_brace = find_matching_brace(text, open_brace)
        if close_brace == -1:
            continue
        methods.append(
            {
                "match": match,
                "body": text[open_brace + 1 : close_brace],
            }
        )
    return methods


def lower_camel(name: str) -> str:
    if not name:
        return name
    return name[:1].lower() + name[1:]


def infer_primary_java_method(text: str, source_path: Path) -> str:
    methods = collect_methods(strip_annotations(text))
    names = [str(item["match"].group("name")) for item in methods]
    if not names:
        return source_path.stem
    class_name = source_path.stem
    preferred = [class_name, lower_camel(class_name)]
    for candidate in preferred:
        if candidate in names:
            return candidate
    return names[0]


def infer_primary_c_function(text: str, fallback: str) -> str:
    names = [name for name in C_FUNC_RE.findall(text) if name != "unknown"]
    return names[0] if names else fallback


def has_recursive_method(text: str) -> bool:
    for item in collect_methods(text):
        match = item["match"]
        name = match.group("name")
        body = str(item["body"])
        if re.search(rf"\b{re.escape(name)}\s*\(", body):
            return True
    return False


def translate_java_to_c(source_path: Path, output_path: Path) -> bool:
    original = source_path.read_text(encoding="utf-8")
    text = strip_annotations(original)
    methods = collect_methods(text)
    if not methods:
        output_path.write_text(
            "/* unsupported translation: no method found */\nint unsupported_translation(void) { return 0; }\n",
            encoding="utf-8",
        )
        return False
    translated: list[dict[str, object]] = []
    includes: set[str] = set()
    overall_ok = True
    method_name_counts: dict[str, int] = {}
    method_param_orders: dict[str, list[tuple[str, str]]] = {}
    for item in methods:
        match = item["match"]
        params = [part.strip() for part in match.group("params").split(",") if part.strip()]
        ordered: list[tuple[str, str]] = []
        for raw in params:
            pieces = raw.split()
            if len(pieces) < 2:
                continue
            java_type = "".join(pieces[:-1])
            name = pieces[-1]
            ordered.append((name, java_type))
        method_param_orders[match.group("name")] = ordered
    for item in methods:
        match = item["match"]
        c_return = primitive_type(match.group("rtype"))
        params, kinds, ok = translate_params(match.group("params"))
        if c_return is None:
            c_return = "int"
            ok = False
        body_text, body_includes, body_ok = replace_body(str(item["body"]), kinds, match.group("rtype"))
        body_text = adapt_method_calls(body_text, method_param_orders)
        ok = ok and body_ok
        includes.update(body_includes)
        base_name = match.group("name")
        count = method_name_counts.get(base_name, 0) + 1
        method_name_counts[base_name] = count
        c_name = base_name if count == 1 else f"{base_name}_{count}"
        translated.append(
            {
                "name": c_name,
                "return": c_return,
                "params": params,
                "body": body_text.rstrip(),
                "supported": ok,
            }
        )
        overall_ok = overall_ok and ok
    banner = "supported" if overall_ok else "best-effort"
    output = []
    output.extend(sorted(includes))
    if output:
        output.append("")
    output.append(f"/* source: {source_path} */")
    output.append(f"/* translation: {banner} */")
    for item in translated:
        if item["supported"]:
            output.append(f"{item['return']} {item['name']}({item['params']});")
    if any(item["supported"] for item in translated):
        output.append("")
    for item in translated:
        if item["supported"]:
            output.append(f"{item['return']} {item['name']}({item['params']}) {{")
            output.append(str(item["body"]))
            output.append("}")
            output.append("")
        else:
            output.append(f"/* unsupported method omitted: {item['name']} */")
    if not any(item["supported"] for item in translated):
        output.append("int unsupported_translation(void) {")
        output.append("    return 0;")
        output.append("}")
    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(strip_all_comments("\n".join(line for line in output if line is not None) + "\n"), encoding="utf-8")
    return overall_ok


def framac_supports_c(source_path: Path) -> bool:
    result = subprocess.run(
        ["opam", "exec", "--switch=frama-c.27.1", "--", "frama-c", "-print", str(source_path)],
        capture_output=True,
        text=True,
    )
    return result.returncode == 0


def nonblank_line_count(text: str) -> int:
    return sum(1 for line in text.splitlines() if line.strip())


def formalbench_java_candidates(formalbench_root: Path) -> list[Path]:
    candidates: list[Path] = []
    for path in sorted(formalbench_root.rglob("*.java")):
        name = path.name
        path_str = str(path)
        if name.endswith("_spec.java") or name.endswith("_wrong.java"):
            continue
        if "/results/" in path_str:
            continue
        candidates.append(path)
    return candidates


def formalbench_hf_root() -> Path | None:
    cache_root = Path.home() / ".cache" / "huggingface" / "hub" / "datasets--thanhlecongg--FormalBench" / "snapshots"
    if not cache_root.exists():
        return None
    snapshots = sorted(path for path in cache_root.iterdir() if path.is_dir())
    return snapshots[-1] if snapshots else None


def formalbench_hf_candidates(hf_root: Path) -> list[Path]:
    candidates: list[Path] = []
    for split in ["base", "diverse"]:
        split_root = hf_root / split
        if not split_root.exists():
            continue
        candidates.extend(sorted(split_root.rglob("*.java")))
    return candidates


def formalbench_score(text: str) -> int:
    loops = len(re.findall(r"\b(for|while)\b", text))
    ifs = len(re.findall(r"\bif\b", text))
    arrays = text.count("[")
    return nonblank_line_count(text) + 8 * loops + 3 * ifs + arrays


def source_prefix(source_repo: str) -> str:
    return {
        "SV-COMP": "SVCOMP",
        "SpecGenBench": "SpecGenBench",
        "FormalBench": "FormalBench",
    }[source_repo]


def local_numeric_loop_sources(src_root: Path) -> list[tuple[str, str, Path]]:
    datasets = [
        ("linear", src_root / "input" / "linear"),
        ("unlinear", src_root / "input" / "NLA_lipus"),
        ("unlinear", src_root / "input" / "numer-s"),
    ]
    files: list[tuple[str, str, Path]] = []
    for bench_bucket, dataset_dir in datasets:
        if not dataset_dir.exists():
            continue
        for path in sorted(dataset_dir.glob("*.c")):
            files.append((bench_bucket, dataset_dir.name, path))
    return files


def translate_c_numeric_loop_to_java(source_path: Path, output_path: Path, dataset_name: str) -> bool:
    text = source_path.read_text(encoding="utf-8", errors="ignore")
    text = strip_all_comments(text)
    lines = [line.rstrip() for line in text.splitlines()]
    cleaned: list[str] = []
    needs_unknown = False
    method_names: list[str] = []

    func_pattern = re.compile(r"^\s*(void|int)\s+([A-Za-z_]\w*)\s*\(([^)]*)\)\s*\{")
    decl_only_pattern = re.compile(r"^\s*int\s+unknown\s*\(\s*\)\s*;\s*$")
    malformed_names_pattern = re.compile(r"^\s*[A-Za-z_]\w*(\s*,\s*[A-Za-z_]\w*)+\s*;\s*$")

    for line in lines:
        stripped = line.strip()
        if not stripped:
            cleaned.append("")
            continue
        if decl_only_pattern.match(stripped):
            needs_unknown = True
            continue
        if malformed_names_pattern.match(stripped):
            continue
        match = func_pattern.match(stripped)
        if match:
            rtype, name, params = match.groups()
            method_names.append(name)
            params = re.sub(r"\bint\s*\*\s*(\w+)", r"int[] \1", params)
            params = re.sub(r"\bint\s+(\w+)\s*\[\s*\]", r"int[] \1", params)
            cleaned.append(f"static {rtype} {name}({params}) {{")
            continue
        stripped = stripped.replace("while (unknown())", "while (unknown() != 0)")
        stripped = re.sub(r"\bint\s*\*\s*(\w+)", r"int[] \1", stripped)
        stripped = re.sub(r"\bint\s+(\w+)\s*\[\s*\]", r"int[] \1", stripped)
        cleaned.append(stripped)

    class_name = re.sub(r"[^A-Za-z0-9_]", "_", output_path.stem)
    java_lines = [f"class {class_name} {{"]
    if needs_unknown:
        java_lines.append("static int unknown() {")
        java_lines.append("return 0;")
        java_lines.append("}")
        java_lines.append("")
    in_method = False
    method_return_type = ""
    method_has_return = False
    brace_depth = 0
    java_func_pattern = re.compile(r"^\s*static\s+(void|int)\s+([A-Za-z_]\w*)\s*\(([^)]*)\)\s*\{")
    for line in cleaned:
        stripped = line.strip()
        match = java_func_pattern.match(stripped)
        if match:
            in_method = True
            method_return_type = match.group(1)
            method_has_return = False
            brace_depth = 1
            java_lines.append(line)
            continue
        if in_method:
            open_count = line.count("{")
            close_count = line.count("}")
            if stripped.startswith("return "):
                method_has_return = True
            if close_count > 0 and brace_depth - close_count + open_count == 0 and method_return_type == "int" and not method_has_return:
                java_lines.append("return 0;")
                method_has_return = True
            java_lines.append(line)
            brace_depth = brace_depth + open_count - close_count
            if brace_depth == 0:
                in_method = False
                method_return_type = ""
                method_has_return = False
            continue
        java_lines.append(line)
    java_lines.append("}")
    java = "\n".join(java_lines).replace("\t", "    ")

    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(strip_all_comments(java), encoding="utf-8")
    return True


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--formalbench-limit", type=int, default=0)
    parser.add_argument("--formalbench-target", type=int, default=100)
    parser.add_argument("--target-total", type=int, default=600)
    args = parser.parse_args()

    ensure_dirs()
    settings = get_settings()
    specgen_root = Path(settings.paths["specgen_root"]) / "benchmark"
    formalbench_root = Path(settings.paths["formalbench_root"])
    bench_root = ROOT / "represent" / "bench"
    java_flat = bench_root / "java_flat"
    c_flat = bench_root / "c_flat"
    mapping_rows: list[tuple[str, str, str, str, str]] = []

    for stale in ["specgen_c", "formalbench_c", "specgen_java_flat", "formalbench_java_flat", "java_flat", "c_flat"]:
        path = bench_root / stale
        if path.exists():
            shutil.rmtree(path)
    java_flat.mkdir(parents=True, exist_ok=True)
    c_flat.mkdir(parents=True, exist_ok=True)

    local_formalbench_files = formalbench_java_candidates(formalbench_root)
    hf_root = formalbench_hf_root()
    hf_formalbench_files = formalbench_hf_candidates(hf_root) if hf_root else []
    formalbench_pool: list[tuple[int, Path, str, Path]] = []
    seen_formalbench: set[str] = set()
    for source in local_formalbench_files:
        original = source.read_text(encoding="utf-8", errors="ignore")
        key = strip_all_comments(original)
        if key in seen_formalbench:
            continue
        seen_formalbench.add(key)
        formalbench_pool.append((formalbench_score(original), source, "FormalBench", source.relative_to(formalbench_root)))
    for source in hf_formalbench_files:
        original = source.read_text(encoding="utf-8", errors="ignore")
        key = strip_all_comments(original)
        if key in seen_formalbench:
            continue
        seen_formalbench.add(key)
        formalbench_pool.append((formalbench_score(original), source, "FormalBench", source.relative_to(hf_root)))
    formalbench_pool.sort(key=lambda item: (item[0], str(item[3])), reverse=True)
    if args.formalbench_limit:
        formalbench_pool = formalbench_pool[: args.formalbench_limit]
    formalbench_index = 1
    selected_source_keys: set[str] = set()
    for _, source, source_kind, rel_path in formalbench_pool:
        if formalbench_index > args.formalbench_target:
            break
        original = source.read_text(encoding="utf-8", errors="ignore")
        source_key = strip_all_comments(original)
        if source_key in selected_source_keys:
            continue
        if has_recursive_method(strip_annotations(original)):
            continue
        stem_prefix = "FormalBenchHF" if rel_path.parts and rel_path.parts[0] in {"base", "diverse"} else "FormalBench"
        stem = "__".join((stem_prefix, *rel_path.with_suffix("").parts))
        prefix = source_prefix(source_kind)
        bench_id = f"{prefix}_{formalbench_index:04d}"
        source_out = java_flat / f"{bench_id}__{stem}.java"
        out = c_flat / f"{bench_id}__{stem}.c"
        function_name = infer_primary_java_method(original, source)
        if not translate_java_to_c(source, out):
            if out.exists():
                out.unlink()
            continue
        if not framac_supports_c(out):
            out.unlink(missing_ok=True)
            continue
        source_out.write_text(strip_all_comments(original), encoding="utf-8")
        selected_source_keys.add(source_key)
        mapping_rows.append((bench_id, source_kind, str(source_out.relative_to(ROOT)), str(out.relative_to(ROOT)), function_name))
        formalbench_index += 1

    specgen_files = sorted(specgen_root.rglob("*.java"))
    specgen_candidates: list[dict[str, object]] = []
    for index, source in enumerate(specgen_files, start=1):
        original = source.read_text(encoding="utf-8")
        rel = source.relative_to(specgen_root)
        stem = "__".join(rel.with_suffix("").parts)
        source_repo = "SV-COMP" if rel.parts and rel.parts[0] == "SVCOMP" else "SpecGenBench"
        prefix = source_prefix(source_repo)
        bench_id = f"{prefix}_{index:04d}"
        java_name = f"{bench_id}__{stem}.java"
        c_name = f"{bench_id}__{stem}.c"
        java_out = java_flat / java_name
        out = c_flat / c_name
        perfect = translate_java_to_c(source, out)
        if not out.exists():
            continue
        source_key = strip_all_comments(original)
        function_name = infer_primary_java_method(original, source)
        java_out.write_text(strip_all_comments(original), encoding="utf-8")
        specgen_candidates.append(
            {
                "index": index,
                "id": bench_id,
                "java_out": java_out,
                "c_out": out,
                "perfect": perfect,
                "length": nonblank_line_count(original),
                "source_key": source_key,
                "source_repo": source_repo,
                "function_name": function_name,
            }
        )

    perfect = [item for item in specgen_candidates if bool(item["perfect"])]
    imperfect = [item for item in specgen_candidates if not bool(item["perfect"])]
    imperfect.sort(key=lambda item: (int(item["length"]), -int(item["index"])), reverse=True)
    specgen_quota = max(0, args.target_total - len(mapping_rows))
    chosen_specgen = perfect[:specgen_quota]
    if len(chosen_specgen) < specgen_quota:
        chosen_specgen.extend(imperfect[: specgen_quota - len(chosen_specgen)])
    chosen_specgen.sort(key=lambda item: int(item["index"]))
    for item in chosen_specgen:
        if str(item["source_key"]) in selected_source_keys:
            continue
        selected_source_keys.add(str(item["source_key"]))
        mapping_rows.append(
            (
                str(item["id"]),
                str(item["source_repo"]),
                str(Path(item["java_out"]).relative_to(ROOT)),
                str(Path(item["c_out"]).relative_to(ROOT)),
                str(item["function_name"]),
            )
        )

    src_root = Path(settings.paths["project_root"]) / "src"
    local_index: dict[str, int] = {"linear": 1, "unlinear": 1}
    for bench_bucket, source_repo_name, source in local_numeric_loop_sources(src_root):
        original = source.read_text(encoding="utf-8", errors="ignore")
        source_key = strip_all_comments(original)
        if source_key in selected_source_keys:
            continue
        selected_source_keys.add(source_key)
        index = local_index[bench_bucket]
        local_index[bench_bucket] += 1
        bench_id = f"SVCOMP_{bench_bucket}_{index:04d}"
        java_out = java_flat / f"{bench_id}__{source.stem}.java"
        c_out = c_flat / f"{bench_id}__{source.stem}.c"
        cleaned_c = strip_all_comments(original)
        c_out.write_text(cleaned_c, encoding="utf-8")
        translate_c_numeric_loop_to_java(source, java_out, bench_bucket)
        function_name = infer_primary_c_function(cleaned_c, source.stem)
        mapping_rows.append((bench_id, "SV-COMP", str(java_out.relative_to(ROOT)), str(c_out.relative_to(ROOT)), function_name))

    mapped_java = {Path(row[2]).name for row in mapping_rows}
    mapped_c = {Path(row[3]).name for row in mapping_rows}
    for stale in java_flat.glob("*.java"):
        if stale.name not in mapped_java:
            stale.unlink()
    for stale in c_flat.glob("*.c"):
        if stale.name not in mapped_c:
            stale.unlink()

    write_mapping(mapping_rows, bench_root / "mapping.tsv")
    print(f"materialized={len(mapping_rows)}")


if __name__ == "__main__":
    main()
