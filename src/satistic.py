import os
import re

def calculate_pass_rates(folder_path):
    """
    遍历指定文件夹下的所有文件，并根据给定的规则计算 Pass Statistics。

    Args:
        folder_path (str): 要Statistics的文件夹路径。
    """
    # 初始化计数器
    syntax_count = {1: 0, 3: 0, 5: 0}
    valid_count = {1: 0, 3: 0, 5: 0}
    satisfy_count = {1: 0, 3: 0, 5: 0}
    total_files = 0

    # 用于从文件内容中提取分数的正则表达式
    score_pattern = re.compile(r"syntax=(\d+|None),\s*valid=(\d+|None),\s*satisfy=(\d+|None)")

    # 遍历文件夹中的所有文件
    for root, dirs, files in os.walk(folder_path):
        for file_name in files:
            file_path = os.path.join(root, file_name)
            
            try:
                with open(file_path, 'r', encoding='utf-8') as f:
                    content = f.read()
                    match = score_pattern.search(content)

                    if not match:
                        print(f"Skipping file '{file_name}' due to missing score pattern.")
                        continue

                    total_files += 1

                    # 提取分数，并处理 None 的情况
                    syntax_score = int(match.group(1)) if match.group(1) != 'None' else None
                    valid_score = int(match.group(2)) if match.group(2) != 'None' else None
                    satisfy_score = int(match.group(3)) if match.group(3) != 'None' else None
                    
            except Exception as e:
                print(f"Error processing file '{file_name}': {e}")
                continue

            # --- 应用你的计算规则 ---
            
            # Syntax Score
            if syntax_score is not None:
                if syntax_score == 1:
                    syntax_count[1] += 1
                    syntax_count[3] += 1
                    syntax_count[5] += 1
                elif syntax_score <= 3:
                    syntax_count[3] += 1
                    syntax_count[5] += 1
                elif syntax_score <= 5:
                    syntax_count[5] += 1

            # Valid Score
            if valid_score is not None:
                if valid_score == 1:
                    valid_count[1] += 1
                    valid_count[3] += 1
                    valid_count[5] += 1
                elif valid_score <= 3:
                    valid_count[3] += 1
                    valid_count[5] += 1
                elif valid_score <= 5:
                    valid_count[5] += 1
            
            # Satisfy Score
            if satisfy_score is not None:
                if satisfy_score == 1:
                    satisfy_count[1] += 1
                    satisfy_count[3] += 1
                    satisfy_count[5] += 1
                elif satisfy_score <= 3:
                    satisfy_count[3] += 1
                    satisfy_count[5] += 1
                elif satisfy_score <= 5:
                    satisfy_count[5] += 1

    # --- Output最终Result ---
    if total_files > 0:
        print(f"\n📊 Total files processed: {total_files}")
        
        print(f"\n📈 Pass@1 Statistics:")
        print(f"  Syntax Rate: {syntax_count[1]/total_files:.2%}")
        print(f"  Valid Rate: {valid_count[1]/total_files:.2%}")
        print(f"  Satisfy Rate: {satisfy_count[1]/total_files:.2%}")
        
        print(f"\n📈 Pass@3 Statistics:")
        print(f"  Syntax Rate: {syntax_count[3]/total_files:.2%}")
        print(f"  Valid Rate: {valid_count[3]/total_files:.2%}")
        print(f"  Satisfy Rate: {satisfy_count[3]/total_files:.2%}")
        
        print(f"\n📈 Pass@5 Statistics:")
        print(f"  Syntax Rate: {syntax_count[5]/total_files:.2%}")
        print(f"  Valid Rate: {valid_count[5]/total_files:.2%}")
        print(f"  Satisfy Rate: {satisfy_count[5]/total_files:.2%}")
    else:
        print("No files containing the specified score pattern were found.")

# --- 脚本运行入口 ---
if __name__ == "__main__":
    # 示例: 指定要Statistics的文件夹路径

    # folder_path_to_scan = "./log/frama-c-loop/gpt-4o"
    # print(f'开始Statistics{folder_path_to_scan}的通过率')
    # calculate_pass_rates(folder_path_to_scan)
    # print('-'*100)

    # folder_path_to_scan = "./log/frama-c-loop/claude-3-7-sonnet-20250219"
    # print(f'开始Statistics{folder_path_to_scan}的通过率')
    # calculate_pass_rates(folder_path_to_scan)

    # folder_path_to_scan = "./log/frama-c-loop/gpt-4o-mini"
    # print(f'开始Statistics{folder_path_to_scan}的通过率')
    # calculate_pass_rates(folder_path_to_scan)

    # folder_path_to_scan = "./log/frama-c/gpt-4o"
    # print(f'开始Statistics{folder_path_to_scan}的通过率')
    # calculate_pass_rates(folder_path_to_scan)
    # print('-'*100)

    # folder_path_to_scan = "./log/frama-c/claude-3-7-sonnet-20250219"
    # print(f'开始Statistics{folder_path_to_scan}的通过率')
    # calculate_pass_rates(folder_path_to_scan)

    # folder_path_to_scan = "./log/frama-c/gpt-4o-mini"
    # print(f'开始Statistics{folder_path_to_scan}的通过率')
    # calculate_pass_rates(folder_path_to_scan)

    # print('='*100)

    # folder_path_to_scan = "./log/oopsla_hola/gpt-4o-mini"
    # print(f'开始Statistics{folder_path_to_scan}的通过率')
    # calculate_pass_rates(folder_path_to_scan)
    # print('-'*100)

    # folder_path_to_scan = "./log/oopsla_hola/gpt-4o"
    # print(f'开始Statistics{folder_path_to_scan}的通过率')
    # calculate_pass_rates(folder_path_to_scan)
    # print('-'*100)

    # folder_path_to_scan = "./log/oopsla_hola/claude-3-7-sonnet-20250219"
    # print(f'开始Statistics{folder_path_to_scan}的通过率')
    # calculate_pass_rates(folder_path_to_scan)

    # print('='*100)
    # folder_path_to_scan = "./log/pIp/gpt-4o-mini"
    # print(f'开始Statistics{folder_path_to_scan}的通过率')
    # calculate_pass_rates(folder_path_to_scan)

    # folder_path_to_scan = "./log/pIp/gpt-4o"
    # print(f'开始Statistics{folder_path_to_scan}的通过率')
    # calculate_pass_rates(folder_path_to_scan)

    # folder_path_to_scan = "./log/pIp/claude-3-7-sonnet-20250219"
    # print(f'开始Statistics{folder_path_to_scan}的通过率')
    # calculate_pass_rates(folder_path_to_scan)

    # folder_path_to_scan = "./log/LIG-MM/gpt-4o-mini"
    # print(f'开始Statistics{folder_path_to_scan}的通过率')
    # calculate_pass_rates(folder_path_to_scan)

    # folder_path_to_scan = "./log/LIG-MM/gpt-4o"
    # print(f'开始Statistics{folder_path_to_scan}的通过率')
    # calculate_pass_rates(folder_path_to_scan)   

    # folder_path_to_scan = "./log/LIG-MM/claude-3-7-sonnet-20250219"
    # print(f'开始Statistics{folder_path_to_scan}的通过率')
    # calculate_pass_rates(folder_path_to_scan)

    # folder_path_to_scan = "./log/function/gpt-4o"
    # print(f'开始Statistics{folder_path_to_scan}的通过率')
    # calculate_pass_rates(folder_path_to_scan)

    # folder_path_to_scan ='./log/loop/gpt-4o'
    # print(f'开始Statistics{folder_path_to_scan}的通过率')
    # calculate_pass_rates(folder_path_to_scan)

    # folder_path_to_scan = "./log/NLA_addition/gpt-3.5-turbo"
    # print(f'开始Statistics{folder_path_to_scan}的通过率')
    # calculate_pass_rates(folder_path_to_scan)

    # folder_path_to_scan = "./log/NLA_addition/claude-3-7-sonnet-20250219"
    # print(f'开始Statistics{folder_path_to_scan}的通过率')
    # calculate_pass_rates(folder_path_to_scan)

    # folder_path_to_scan = "./log/NLA_addition/gpt-4o-mini"
    # print(f'开始Statistics{folder_path_to_scan}的通过率')
    # calculate_pass_rates(folder_path_to_scan)

    # folder_path_to_scan = "./log/NLA_addition/gpt-4o"
    # print(f'开始Statistics{folder_path_to_scan}的通过率')
    # calculate_pass_rates(folder_path_to_scan)


    folder_path_to_scan = "./log/linear/gpt-4o-mini"
    print(f'开始Statistics{folder_path_to_scan}的通过率')
    calculate_pass_rates(folder_path_to_scan)

   