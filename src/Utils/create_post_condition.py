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
    return code


def _strip_qcp_unsupported_prelude(code: str) -> str:
    code = re.sub(r"^\s*#\s*include\s*<[^>]+>\s*\n", "", code, flags=re.MULTILINE)
    prototype = re.compile(
        r"^\s*(?:[A-Za-z_][A-Za-z0-9_]*\s+|struct\s+[A-Za-z_][A-Za-z0-9_]*\s+|\*\s*)+"
        r"[A-Za-z_][A-Za-z0-9_]*\s*\([^;{}]*\)\s*;\s*\n",
        flags=re.MULTILINE,
    )
    return prototype.sub("", code)


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
    return "".join(parts)


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
