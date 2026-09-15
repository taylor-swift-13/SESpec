#!/usr/bin/env python3
"""Reproducible Java/C differential smoke test for SESpec-400 translations.

A case is reported as agreeing only on inputs terminating normally on both sides.
"""

import concurrent.futures
import json
import math
import random
import re
import shutil
import subprocess
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
DATA = ROOT / "RESULTS/paper_data"
OUT = DATA / "appendix_d_translation" / "semantic_checks"
TIMEOUT = 1.5


def run(command, cwd=None, timeout=TIMEOUT):
    try:
        p = subprocess.run(command, cwd=cwd, text=True, capture_output=True,
                           timeout=timeout)
        return (p.returncode, p.stdout.strip(), p.stderr.strip()[:500])
    except subprocess.TimeoutExpired:
        return (-99, "", "timeout")


def parse(i):
    source = next((DATA / "benchmark" / "java_inputs").glob(f"{i:03d}_*.java"))
    js = source.read_text()
    cs = (DATA / "benchmark" / "c_inputs" / f"{i}.c").read_text()
    cm = re.search(r"^\s*(.*?)\s+foo" + str(i) + r"\s*\(([^)]*)\)\s*;", cs, re.M)
    cls = re.search(r"\bclass\s+(\w+)", js)
    if not cm or not cls or cm[1].strip() not in ("int", "void", "double", "long long", "const char *"):
        return None, "unsupported_return_or_class"
    c_types = []
    for x in cm[2].split(","):
        x = x.strip()
        if x:
            x = re.sub(r"\bint\s+\w+\[\]", "int *", x)
            c_types.append(re.sub(r"\s*\w+\s*$", "", x).strip())
    methods = re.findall(
        r"(?m)^\s*((?:(?:public|private|protected|static|final)\s+)*)"
        r"(int|boolean|void|double|long|String)\s+(\w+)\s*\(([^)]*)\)\s*\{", js)
    candidates = []
    retmap = {"int": "int", "boolean": "int", "void": "void",
              "double": "double", "long": "long long", "String": "const char *"}
    argmap = {"int": ["int"], "int[]": ["int *", "int"],
              "int[][]": ["int * *", "int", "int", "int"],
              "char[]": ["const char *"], "String": ["const char *"],
              "char": ["char"], "double": ["double"],
              "long": ["long long"], "short": ["short"]}
    for mods, ret, name, args in methods:
        types = [re.sub(r"\s+\w+\s*$", "", a.strip()).strip()
                 for a in args.split(",") if a.strip()]
        if all(x in argmap for x in types) and [t for x in types for t in argmap[x]] == c_types and retmap[ret] == cm[1].strip():
            candidates.append((mods, ret, name, types))
    if not candidates:
        return None, "unsupported_signature"
    if len(candidates) > 1:
        exact = [x for x in candidates if x[2] == f"foo{i}"]
        if len(exact) == 1:
            candidates = exact
        else:
            candidates = [candidates[-1]]
    mods, ret, method, types = candidates[0]
    return dict(i=i, source=source, java=js, c=cs, cls=cls[1],
                method=method, static="static" in mods.split(), types=types, ret=ret), None


def inputs(i, types):
    patterns = [[], [0], [1], [-1], [0, 1, 2], [1, 2, 3, 4],
                [4, 3, 2, 1], [1, 1, 1, 1], [0] * 8,
                [1] * 8, list(range(8))]
    rng = random.Random(20260914 + i)
    cases = []
    for k in range(16):
        vals = []
        for t in types:
            if t == "int[]":
                vals.append(patterns[(k + len(vals)) % len(patterns)]
                            if k < 11 else [rng.randrange(-3, 7) for _ in range(8)])
            elif t == "int[][]":
                vals.append([[0, 0], [1, 0], [0, 1]] if k % 4 == 0 else
                            [[(r + k) % 4, (r + k + 1) % 4] for r in range(8)])
            elif t in ("String", "char[]"):
                vals.append(["", "a", "ab", "aba", "abc", "b", "0", "11", "hello", "xyz", "aaaa", "abcabc", "q", "z", "abca", "ba"][k])
            elif t == "char":
                vals.append(["+", "-", "*", "/", "%", "x", "+", "-", "*", "/", "%", "x", "+", "-", "*", "x"][k])
            else:
                vals.append(([0, 1, 2, 3, 4, -1, 8, 5, 0, 1, 2, 3, 4, 5, -2, 6][k]))
        cases.append(vals)
    return cases


def java_driver(meta):
    exprs, prints = [], []
    for j, t in enumerate(meta["types"]):
        if t in ("int", "long", "double"):
            exprs.append(f"Integer.parseInt(args[{j}])")
        elif t == "short":
            exprs.append(f"(short)Integer.parseInt(args[{j}])")
        elif t == "char":
            exprs.append(f"args[{j}].charAt(0)")
        elif t == "String":
            exprs.append(f"args[{j}]")
        elif t == "char[]":
            exprs.append(f"args[{j}].toCharArray()")
        elif t == "int[][]":
            exprs.append(f"m{j}")
        else:
            exprs.append(f"a{j}")
            prints.append(f"for (int v : a{j}) System.out.print(\",\" + v);")
    parse_arrays = []
    for j, t in enumerate(meta["types"]):
        if t == "int[]":
            parse_arrays.append(f'''int[] a{j} = args[{j}].isEmpty() ? new int[0] :
                java.util.Arrays.stream(args[{j}].split(",")).mapToInt(Integer::parseInt).toArray();''')
        elif t == "int[][]":
            parse_arrays.append(f'''String[] rows{j} = args[{j}].split(";", -1);
                int[][] m{j} = new int[rows{j}.length][];
                for(int r=0;r<rows{j}.length;r++)
                  m{j}[r] = java.util.Arrays.stream(rows{j}[r].split(",")).mapToInt(Integer::parseInt).toArray();''')
    target = meta["cls"] if meta["static"] else f"new {meta['cls']}()"
    call = f"{target}.{meta['method']}({', '.join(exprs)})"
    if meta["ret"] == "void":
        invoke = f"{call}; System.out.print(\"VOID\");"
    elif meta["ret"] == "boolean":
        invoke = f"boolean result = {call}; System.out.print(result ? 1 : 0);"
    else:
        invoke = f"{meta['ret']} result = {call}; System.out.print(result);"
    return f'''public class DiffDriver {{
      public static void main(String[] args) {{
        try {{
          {' '.join(parse_arrays)}
          {invoke}
          {' '.join(prints)}
        }} catch (Throwable e) {{ System.out.print("EXCEPTION:" + e.getClass().getName()); }}
      }}
    }}'''


def c_driver(meta):
    setup, exprs, prints = [], [], []
    for j, t in enumerate(meta["types"]):
        if t in ("int", "short", "long", "double"):
            exprs.append(f"atoi(argv[{j+1}])")
        elif t in ("String", "char[]"):
            exprs.append(f"argv[{j+1}]")
        elif t == "char":
            exprs.append(f"argv[{j+1}][0]")
        elif t == "int[][]":
            setup.append(f'''int data{j}[64][64], *m{j}[64], nr{j}=0, nc{j}=0;
              char buf{j}[1024]; snprintf(buf{j}, sizeof(buf{j}), "%s", argv[{j+1}]);
              char *save_outer{j}=NULL, *save_inner{j}=NULL;
              for(char *row=strtok_r(buf{j}, ";", &save_outer{j}); row && nr{j}<64;
                  row=strtok_r(NULL, ";", &save_outer{j})) {{
                m{j}[nr{j}]=data{j}[nr{j}]; int cc=0;
                for(char *cell=strtok_r(row, ",", &save_inner{j}); cell && cc<64;
                    cell=strtok_r(NULL, ",", &save_inner{j})) data{j}[nr{j}][cc++]=atoi(cell);
                nc{j}=cc; nr{j}++;
              }}''')
            exprs.extend([f"m{j}", f"nr{j}", f"nr{j}", f"nc{j}"])
        else:
            setup.append(f'''int a{j}[64], n{j}=0;
              char buf{j}[512]; snprintf(buf{j}, sizeof(buf{j}), "%s", argv[{j+1}]);
              for(char *p=strtok(buf{j}, ","); p && n{j}<64; p=strtok(NULL, ",")) a{j}[n{j}++]=atoi(p);''')
            exprs.extend([f"a{j}", f"n{j}"])
            prints.append(f'''for(int k=0;k<n{j};k++) printf(",%d", a{j}[k]);''')
    if meta["ret"] == "void":
        invoke = f"foo{meta['i']}({', '.join(exprs)}); printf(\"VOID\");"
    elif meta["ret"] == "String":
        invoke = f"const char *result=foo{meta['i']}({', '.join(exprs)}); printf(\"%s\",result ? result : \"NULL\");"
    elif meta["ret"] == "double":
        invoke = f"double result=foo{meta['i']}({', '.join(exprs)}); printf(\"%.17g\",result);"
    elif meta["ret"] == "long":
        invoke = f"long long result=foo{meta['i']}({', '.join(exprs)}); printf(\"%lld\",result);"
    else:
        invoke = f"int result=foo{meta['i']}({', '.join(exprs)}); printf(\"%d\",result);"
    return f'''#include <stdio.h>
      #include <stdlib.h>
      #include <string.h>
      {meta['c']}
      int main(int argc, char **argv) {{
        if(argc!={len(meta['types'])+1}) return 20;
        {' '.join(setup)}
        {invoke}
        {' '.join(prints)}
        return 0;
      }}'''


def evaluate(i):
    meta, reason = parse(i)
    if reason:
        return dict(index=i, status="unsupported", reason=reason)
    with tempfile.TemporaryDirectory(prefix=f"translation_{i}_") as temp:
        work = Path(temp)
        (work / f"{meta['cls']}.java").write_text(meta["java"])
        (work / "DiffDriver.java").write_text(java_driver(meta))
        (work / "diff.c").write_text(c_driver(meta))
        jr = run(["javac", "--release", "8", f"{meta['cls']}.java", "DiffDriver.java"], work, 25)
        if jr[0] != 0:
            return dict(index=i, status="unrunnable", reason="javac", detail=jr[2])
        cr = run(["gcc", "-std=c11", "-D_POSIX_C_SOURCE=200809L", "-O0", "-fsanitize=undefined", "-fno-sanitize-recover=all",
                  "diff.c", "-o", "diff"], work, 25)
        if cr[0] != 0:
            return dict(index=i, status="unrunnable", reason="gcc", detail=cr[2])
        match = mismatch = out_of_scope = java_exception = 0
        first_mismatch = None
        for vals in inputs(i, meta["types"]):
            args = [(";".join(",".join(map(str, row)) for row in x)
                     if x and isinstance(x[0], list) else ",".join(map(str, x)))
                    if isinstance(x, list) else str(x) for x in vals]
            j = run(["java", "-cp", str(work), "DiffDriver", *args], work)
            if j[0] != 0 or j[1].startswith("EXCEPTION:"):
                java_exception += 1
                continue
            c = run([str(work / "diff"), *args], work)
            if c[0] != 0:
                out_of_scope += 1
                mismatch += 1
                if first_mismatch is None:
                    first_mismatch = dict(input=vals, java=j[1], c="C_ABNORMAL", detail=c[2])
                continue
            equivalent = j[1] == c[1]
            if meta["ret"] == "double" and not equivalent:
                try:
                    equivalent = math.isclose(float(j[1]), float(c[1]), rel_tol=1e-12, abs_tol=1e-12)
                except ValueError:
                    pass
            if equivalent:
                match += 1
            else:
                mismatch += 1
                if first_mismatch is None:
                    first_mismatch = dict(input=vals, java=j[1], c=c[1])
        return dict(index=i, status="mismatch" if mismatch else "agree" if match else "no_common_input",
                    match=match, mismatch=mismatch, java_exception=java_exception,
                    c_abnormal=out_of_scope, first_mismatch=first_mismatch)


def main():
    OUT.mkdir(parents=True, exist_ok=True)
    rows = []
    with concurrent.futures.ThreadPoolExecutor(max_workers=8) as pool:
        for row in pool.map(evaluate, range(91, 400)):
            rows.append(row)
            if len(rows) % 25 == 0:
                print(f"{len(rows)}/309", flush=True)
    (OUT / "differential_results.json").write_text(json.dumps(rows, indent=2))
    summary = dict(total=len(rows), statuses={s:sum(x["status"]==s for x in rows)
                                             for s in sorted({x["status"] for x in rows})},
                   matched_inputs=sum(x.get("match", 0) for x in rows),
                   mismatched_inputs=sum(x.get("mismatch", 0) for x in rows),
                   java_exceptions=sum(x.get("java_exception", 0) for x in rows),
                   c_abnormal=sum(x.get("c_abnormal", 0) for x in rows))
    (OUT / "summary.json").write_text(json.dumps(summary, indent=2))
    print(json.dumps(summary, indent=2), flush=True)


if __name__ == "__main__":
    main()
