import argparse
import subprocess
import logging
from .syntax_checker import SyntaxChecker
from config import MainConfig
import re

class OutputVerifier:
    def __init__(self,config:MainConfig,logger:logging.Logger,output:bool=False):
        self.config = config
        self.logger = logger
        self.output = output
        self.syntax_error = ''
        self.valid_error_list = []
        self.verify_error_list = []
        self.verify_result = []
        self.validate_result =[]
        self.status_summary = {
            "file_path": "",
            "syntax_status": "no_result",
            "validity_status": "no_result",
            "satisfy_status": "no_result",
            "failure_reason": "not_run",
        }

    def print_errors(self, error_list):
        for error in error_list:
            print(error[0].splitlines()[0])  # Print error description
            print(error[1])  # Print error file location
            print(error[2])  # Print error line content
            print()

    def _goal_header(self, goal_block):
        for line in goal_block.splitlines():
            line = line.strip()
            if line.startswith("Goal "):
                return line
        return "Goal <unknown>"

    def _log_goal_results(self, section_name, goals):
        self.logger.info(f"{section_name} VC Details:")
        if not goals:
            self.logger.info("[]")
        for index, goal in enumerate(goals, start=1):
            status = "Valid" if "Valid" in goal else "Invalid"
            self.logger.info(f"[{index}] {status} - {self._goal_header(goal)}")
        self.logger.info('')
    

    def extract_semantic_error(self,error_message):
        # Use regular expression to extract filename and line number
        pattern = r'file\s+([\w\/\.\-]+),\s+line\s+(\d+)'
        match = re.search(pattern, error_message)
        
        if match:
            file_path = match.group(1)
            line_number = int(match.group(2))  # Convert to integer

            try:
                with open(file_path, 'r') as file:
                    # Read all lines of the file
                    lines = file.readlines()
                    # Check if line number is within file range
                    if 1 <= line_number <= len(lines):
                        error_line = lines[line_number - 1].strip()  # Extract error line content
                    else:
                        error_line = None  # Line number out of range
                    
            except FileNotFoundError:
                print(f"Error: File '{file_path}' not found.")
                return None, None

            # Construct error location information and error line content information
            error_location_msg = f"Error found in file: {file_path} at line: {line_number}"
            error_content_msg = f"Error line content: {error_line}" if error_line else "Error line content: Line number out of range or file could not be read."

            return error_location_msg, error_content_msg
        
        else:
            return None, None
    

    def check_valid_pairs(self, filter_invs):
        results = []
        # Group by adjacent identical elements
        for i in range(0, len(filter_invs), 2):
            if i + 1 < len(filter_invs) and "Valid" in str(filter_invs[i]) and "Valid" in str(filter_invs[i+1]):
                results.append(True)
            else:
                results.append(False)
        return results

    def check_verify_target(self, filter_contents):
        results = []
        for content in filter_contents:
            if 'Valid' in content:
                results.append(True)
            else:
                results.append(False)
        return results

    def filter_goal_assertion(self, contents):
        return [line for line in contents if line.strip().startswith("Goal Assertion (")]

    def filter_invariant(self, contents):
        return [line for line in contents if line.strip().startswith("Goal Establishment of Invariant") or line.strip().startswith("Goal Preservation of Invariant")]

    def parse_args(self):
        parser = argparse.ArgumentParser(description="Run Frama-C WP on a C file.")
        parser.add_argument('file_name', help="Path to the C file to analyze")
        return parser.parse_args()
    
    def run(self,file_name=None):

        if file_name != None:
            file_path = f"{self.config.generated_loop_c_file_path}/{file_name}.c"
        else :
            args = self.parse_args()
            file_path = f"{self.config.generated_loop_c_file_path}/{args.file_name}.c"
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

        if self.config.debug and self.output:
                self.logger.info(syntax_msg)

        if syntax_msg !='syntax Correct':
            self.syntax_error = syntax_msg
            self.status_summary.update(
                {
                    "syntax_status": "fail",
                    "validity_status": "no_result",
                    "satisfy_status": "no_result",
                    "failure_reason": "syntax_error",
                }
            )
        else:
            self.status_summary["syntax_status"] = "pass"
            frama_c_command = "frama-c"
            wp_command = [frama_c_command, "-wp", "-wp-print", "-wp-timeout", "10", "-wp-prover", "z3", "-wp-model", "Typed", file_path]
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

            filter_invs = self.filter_invariant(contents)
            self.validate_result = self.check_valid_pairs(filter_invs)
            if not filter_invs:
                self.status_summary["validity_status"] = "no_result"
                self.status_summary["failure_reason"] = "no_invariants_extracted"
            else:
                self.status_summary["validity_status"] = "pass" if all(self.validate_result) else "fail"

            for item in filter_invs:
                if 'Valid' not in item:
                    valid_error_msg = item
                    error_location_msg, error_content_msg = self.extract_semantic_error(valid_error_msg)
                    self.valid_error_list.append((valid_error_msg.strip(), error_location_msg, error_content_msg))

            if self.config.debug and self.output:
                self.logger.info('Validate:')
                self.logger.info(self.validate_result)
                self.logger.info('')
                self._log_goal_results('Validate', filter_invs)
                self.print_errors(self.valid_error_list)

            filter_contents = self.filter_goal_assertion(contents)
            self.verify_result = self.check_verify_target(filter_contents)
            if not filter_contents:
                self.status_summary["satisfy_status"] = "pass"
            else:
                self.status_summary["satisfy_status"] = "pass" if all(self.verify_result) else "fail"

            for item in filter_contents:
                if 'Valid' not in item:
                    verify_error_msg = item
                    error_location_msg, error_content_msg = self.extract_semantic_error(verify_error_msg)
                    self.verify_error_list.append((verify_error_msg.strip(), error_location_msg, error_content_msg))
            if self.config.debug and self.output:
                self.logger.info('Verify:')
                self.logger.info(self.verify_result)
                self.logger.info('')
                self._log_goal_results('Verify', filter_contents)
                self.print_errors(self.verify_error_list)

            if self.status_summary["failure_reason"] == "not_run":
                if self.status_summary["validity_status"] == "fail":
                    self.status_summary["failure_reason"] = "verification_failed"
                elif self.status_summary["satisfy_status"] == "fail":
                    self.status_summary["failure_reason"] = "assertion_failed"
                else:
                    self.status_summary["failure_reason"] = "pass"

    

if __name__ == "__main__":
    verifier = OutputVerifier()
    verifier.run()
