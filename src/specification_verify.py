import argparse
import subprocess
import logging
from LoopInvGen.syntax_checker import SyntaxChecker
from config import MainConfig
import re

class SpecVerifier:
    def __init__(self,config:MainConfig,logger:logging.Logger = None):
        self.config = config
        self.logger = logger
        self.file_name = None
        self.syntax_error = ''
        self.syntax_bool = None
        self.loop_error_list = []
        self.assert_error_list = []
        self.post_error_list = []
        self.instance_error_list = []
        self.loop_result = []
        self.assigns_result = []
        self.assert_result =[]
        self.post_result =[]
        self.instance_result=[]
        self.status_summary = {
            "file_path": "",
            "syntax_status": "no_result",
            "validity_status": "no_result",
            "satisfy_status": "no_result",
            "failure_reason": "not_run",
        }
       

    def print_errors(self, error_list):
        for error in error_list:
            print(error[0])  # 打印Error描述
            print(error[1])  # 打印Error文件位置
            print(error[2])  # 打印Error行内容
            print()

    def _goal_header(self, goal_block):
        for line in goal_block.splitlines():
            line = line.strip()
            if line.startswith("Goal "):
                return line
        return "Goal <unknown>"

    def _log_goal_results(self, section_name, goals):
        if self.logger:
            self.logger.info(f"{section_name} VC Details:")
            if not goals:
                self.logger.info("[]")
            for index, goal in enumerate(goals, start=1):
                status = "Valid" if "Valid" in goal else "Invalid"
                self.logger.info(f"[{index}] {status} - {self._goal_header(goal)}")
            self.logger.info('')
        else:
            print(f"{section_name} VC Details:")
            if not goals:
                print("[]")
            for index, goal in enumerate(goals, start=1):
                status = "Valid" if "Valid" in goal else "Invalid"
                print(f"[{index}] {status} - {self._goal_header(goal)}")
            print('')
    
    def log_errors(self):
        # 创建一个字符串来存储日志内容
        log_content = ""

        # 添加Filename
        log_content += f"File Name: {self.file_name}\n\n"

        # 添加 syntax_error
        log_content += "Syntax Error:\n"
        log_content += f"{self.syntax_error}\n\n"

        # 添加 Loop Invariant Errors
        log_content += "Loop Invariant Errors:\n"
        if self.loop_error_list:
            for error in self.loop_error_list:
                log_content += f"- {error}\n"
        else:
            log_content += "No Loop Invariant Errors.\n"
        log_content += "\n"

        # 添加 Loop Invariant Results
        log_content += "Loop Invariant Results:\n"
        if self.loop_result:
            for result in self.loop_result:
                log_content += f"- {result}\n"
        else:
            log_content += "No Loop Invariant Results.\n"
        log_content += "\n"

        # 添加 Assertion Errors
        log_content += "Assertion Errors:\n"
        if self.assert_error_list:
            for error in self.assert_error_list:
                log_content += f"- {error}\n"
        else:
            log_content += "No Assertion Errors.\n"
        log_content += "\n"

        # 添加 Assertion Results
        log_content += "Assertion Results:\n"
        if self.assert_result:
            for result in self.assert_result:
                log_content += f"- {result}\n"
        else:
            log_content += "No Assertion Results.\n"
        log_content += "\n"

        # 添加 Postcond Errors
        log_content += "Postcond Errors:\n"
        if self.post_error_list:
            for error in self.post_error_list:
                log_content += f"- {error}\n"
        else:
            log_content += "No Postcond Errors.\n"
        log_content += "\n"

        # 添加 Postcond Results
        log_content += "Postcond Results:\n"
        if self.post_result:
            for result in self.post_result:
                log_content += f"- {result}\n"
        else:
            log_content += "No Postcond Results.\n"
        log_content += "\n"

        # 添加分隔线
        log_content += '------------------------------------------------\n'

        # 返回日志内容
        return log_content

    def log_accury(self):
        
        def calculate_accuracy(bool_array):
            if not bool_array:  # 如果数组为空，返回 0
                return 0.0
            return (sum(bool_array) / len(bool_array)) * 100  # 转换为百分数
        
        loop_accuracy = calculate_accuracy(self.loop_result)
        assert_accuracy = calculate_accuracy(self.assert_result)
        post_accuracy = calculate_accuracy(self.post_result)
        

        # 计算总的正确率
        combined_results = self.loop_result + self.assert_result + self.post_result
        total_accuracy = calculate_accuracy(combined_results)
        
        accuracy_log = f'''
File Name: {self.file_name}
synatax_accuracy: {self.syntax_bool}
loop_accuracy:  {loop_accuracy:.2f}% ({sum(self.loop_result)}/{len(self.loop_result)})
assert_accuracy:  {assert_accuracy:.2f}% ({sum(self.assert_result)}/{len(self.assert_result)})
post_accuracy:  {post_accuracy:.2f}%  ({sum(self.post_result)}/{len(self.post_result)})
total_accuracy:  {total_accuracy:.2f}% ({sum(combined_results)}/{len(combined_results)})
'''
        # print(accuracy_log)
        return accuracy_log

    def extract_semantic_error(self,error_message):
        # 使用正则表达式提取Filename和行号
        pattern = r'file\s+([\w\/\.\-]+),\s+line\s+(\d+)'
        match = re.search(pattern, error_message)
        
        if match:
            file_path = match.group(1)
            line_number = int(match.group(2))  # 转换为整数

            try:
                with open(file_path, 'r') as file:
                    # 读取文件的所有行
                    lines = file.readlines()
                    # 检查行号是否在文件范围内
                    if 1 <= line_number <= len(lines):
                        error_line = lines[line_number - 1].strip()  # 提取Error行内容
                    else:
                        error_line = None  # 行号超出范围
                    
            except FileNotFoundError:
                print(f"Error: File '{file_path}' not found.")
                return None, None

            # 构造Error位置信息和Error行内容信息
            error_location_msg = f"Error found in file: {file_path} at line: {line_number}"
            error_content_msg = f"Error line content: {error_line}" if error_line else "Error line content: Line number out of range or file could not be read."

            return error_location_msg, error_content_msg
        
        else:
            return None, None
    

    def check_pairs(self, filter_invs):
        results = []
        # 按相邻相同的元素分组
        for i in range(0, len(filter_invs), 2):
            if i + 1 < len(filter_invs) and "Valid" in str(filter_invs[i]) and "Valid" in str(filter_invs[i+1]):
                results.append(True)
            else:
                results.append(False)
        return results

    def check_target(self, filter_contents):
        results = []
        for content in filter_contents:
            if 'Valid' in content:
                results.append(True)
            else:
                results.append(False)
        return results

    def filter_goal_assertion(self, contents):
        return [line for line in contents if line.strip().startswith("Goal Assertion ")]

    def filter_goal_assigns(self, contents):
        return [line for line in contents if line.strip().startswith("Goal Assigns ")]

    def filter_invariant(self, contents):
        return [line for line in contents if line.strip().startswith("Goal Establishment of Invariant") or line.strip().startswith("Goal Preservation of Invariant")]

    def filter_post_condition(self, contents):
        return [line for line in contents if line.strip().startswith("Goal Post-condition")]

    def filter_instance(self,contents):
        return [line for line in contents if line.strip().startswith("Goal Instance")]
    

    
    def parse_args(self):
        parser = argparse.ArgumentParser(description="Run Frama-C WP on a C file.")
        parser.add_argument('file_name', help="Path to the C file to analyze")
        return parser.parse_args()
    
    def run(self,file_name=None):

        if file_name != None:
            file_path = f"{self.config.output_path}/{file_name}.c"
        else :
            args = self.parse_args()
            file_path = f"{self.config.output_path}/{args.file_name}.c"
        self.status_summary = {
            "file_path": file_path,
            "syntax_status": "no_result",
            "validity_status": "no_result",
            "satisfy_status": "no_result",
            "failure_reason": "not_run",
        }

        
        # syntax_msg = subprocess.run(['python3', 'syntaxChecker.py', file_path], capture_output=True, text=True).stdout
        # print(syntax_msg)

        checker = SyntaxChecker()
        checker.run(file_path)
        syntax_msg = checker.syntax_msg
        if self.logger:
            self.logger.info(syntax_msg)
        else:
            print(syntax_msg)

        if syntax_msg !='syntax Correct':
            self.syntax_error = syntax_msg
            self.syntax_bool = False
            self.status_summary.update(
                {
                    "syntax_status": "fail",
                    "validity_status": "no_result",
                    "satisfy_status": "no_result",
                    "failure_reason": "syntax_error",
                }
            )
        else:
            self.syntax_bool = True
            self.status_summary["syntax_status"] = "pass"
            frama_c_command = "frama-c"
            wp_command = [frama_c_command, "-wp", "-wp-print", "-wp-timeout", "10", "-wp-prover", "z3", "-wp-model", "Typed",  file_path]
            # wp_command = [frama_c_command, "-wp", "-wp-print", "-wp-timeout", "3", "-wp-prover", "z3", "-wp-model", "Typed+Caveat", file_path]
            try:
                result = subprocess.run(wp_command, capture_output=True, text=True, check=True)
            except subprocess.CalledProcessError as exc:
                self.syntax_error = exc.stderr or exc.stdout
                self.status_summary.update(
                    {
                        "validity_status": "no_result",
                        "satisfy_status": "no_result",
                        "failure_reason": "verifier_no_output",
                    }
                )
                return
            spliter = '------------------------------------------------------------'
            content = result.stdout
            contents = content.split(spliter)
            #print(content)
            
    
            filter_invs = self.filter_invariant(contents)
            self.loop_result = self.check_pairs(filter_invs)

            for item in filter_invs:
                if 'Valid' not in item:
                    loop_error_msg = item
                    error_location_msg, error_content_msg = self.extract_semantic_error(loop_error_msg)
                    self.loop_error_list.append((loop_error_msg.strip(), error_location_msg, error_content_msg))
            
            if self.logger:
                self.logger.info('Loop Invariant:')
                self.logger.info(self.loop_result)
                self.logger.info('')
                self._log_goal_results('Loop Invariant', filter_invs)
            else:
                print('Loop Invariant:')
                print(self.loop_result)
                print('')
                self._log_goal_results('Loop Invariant', filter_invs)
            # self.print_errors(self.loop_error_list)

            filter_assigns = self.filter_goal_assigns(contents)
            self.assigns_result = self.check_target(filter_assigns)
            for item in filter_assigns:
                if 'Valid' not in item:
                    assign_error_msg = item
                    error_location_msg, error_content_msg = self.extract_semantic_error(assign_error_msg)
                    self.assert_error_list.append((assign_error_msg.strip(),error_location_msg, error_content_msg))

            if self.logger:
                self.logger.info('Assigns:')
                self.logger.info(self.assigns_result)
                self.logger.info('')
                self._log_goal_results('Assigns', filter_assigns)
            else:
                print('Assigns:')
                print(self.assigns_result)
                print('')
                self._log_goal_results('Assigns', filter_assigns)

            filter_contents = self.filter_goal_assertion(contents)
            self.assert_result = self.check_target(filter_contents)

            for item in filter_contents:
                if 'Valid' not in item:
                    assert_error_msg = item
                    error_location_msg, error_content_msg = self.extract_semantic_error(assert_error_msg)
                    self.assert_error_list.append((assert_error_msg.strip(),error_location_msg, error_content_msg))

            if self.logger:
                self.logger.info('Assertion:')
                self.logger.info(self.assert_result)
                self.logger.info('')
                self._log_goal_results('Assertion', filter_contents)
            else:
                print('Assertion:')
                print(self.assert_result)
                print('')
                self._log_goal_results('Assertion', filter_contents)
            # self.print_errors(self.assert_error_list)

            filter_postconds = self.filter_post_condition(contents)
            self.post_result = self.check_target(filter_postconds)
            if filter_contents:
                self.status_summary["satisfy_status"] = "pass" if all(self.assert_result) else "fail"
            else:
                self.status_summary["satisfy_status"] = "pass"
                if not filter_postconds and self.status_summary["failure_reason"] in ["not_run", "no_invariants_extracted"]:
                    self.status_summary["failure_reason"] = "no_target"
            
            for item in filter_postconds:
                if 'Valid' not in item:
                    post_error_msg = item
                    error_location_msg, error_content_msg = self.extract_semantic_error(post_error_msg)
                    self.post_error_list.append((post_error_msg.strip(),error_location_msg, error_content_msg))
            
            if self.logger:
                self.logger.info('Post Condition:')
                self.logger.info(self.post_result)
                self.logger.info('')
                self._log_goal_results('Post Condition', filter_postconds)
            else:
                print('Post Condition:')
                print(self.post_result)
                print('')
                self._log_goal_results('Post Condition', filter_postconds)
            # self.print_errors(self.post_error_list)

            filter_instance = self.filter_instance(contents)
            self.instance_result = self.check_target(filter_instance)
            
            for item in filter_instance:
                if 'Valid' not in item:
                    instance_error_msg = item
                    error_location_msg, error_content_msg = self.extract_semantic_error(instance_error_msg)
                    self.instance_error_list.append((instance_error_msg.strip(),error_location_msg, error_content_msg))
            
            if self.instance_result:
                if self.logger:
                    self.logger.info('Instance:')
                    self.logger.info(self.instance_result)
                    self.logger.info('')
                    self._log_goal_results('Instance', filter_instance)
                else:
                    print('Instance:')
                    print(self.instance_result)
                    print('')
                    self._log_goal_results('Instance', filter_instance)
            validity_groups = []
            if filter_invs:
                validity_groups.append(all(self.loop_result))
            if filter_assigns:
                validity_groups.append(all(self.assigns_result))
            if filter_postconds:
                validity_groups.append(all(self.post_result))
            if filter_instance:
                validity_groups.append(all(self.instance_result))
            if validity_groups:
                self.status_summary["validity_status"] = "pass" if all(validity_groups) else "fail"
            else:
                self.status_summary["validity_status"] = "no_result"
            if self.status_summary["validity_status"] == "fail":
                self.status_summary["failure_reason"] = "verification_failed"
            elif self.status_summary["satisfy_status"] == "fail":
                self.status_summary["failure_reason"] = "assertion_failed"
            elif self.status_summary["validity_status"] == "pass" and self.status_summary["satisfy_status"] == "pass":
                self.status_summary["failure_reason"] = "pass"
            elif self.status_summary["failure_reason"] == "not_run":
                self.status_summary["failure_reason"] = "no_invariants_extracted"





    
