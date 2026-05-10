import subprocess
import argparse

class SyntaxChecker:
    def __init__(self):
        self.syntax_msg = ""  # Used to store all output content

    def parse_args(self):
        """Set up command line argument parser"""
        parser = argparse.ArgumentParser(description="Run Frama-C WP on a C file.")
        parser.add_argument('file_name', help="Path to the C file to analyze")
        return parser.parse_args()

    def run(self, file_name=None):
        """Run Frama-C WP command and process output"""
        if file_name is None:
            # If no file_name passed, get from command line arguments
            args = self.parse_args()
            file_path = args.file_name
        else:
            # If file_name passed, use it directly
            file_path = file_name

        # Generate WP verification command
        wp_command = [
            "frama-c",
            "-wp",
            "-wp-print",
            "-wp-timeout",
            "3",
            file_path
        ]

        try:
            # Use subprocess.run to execute command and capture output
            result = subprocess.run(wp_command, capture_output=True, text=True, check=True)
            self.syntax_msg = "syntax Correct"
        except subprocess.CalledProcessError as e:
            # If command execution fails, capture error information
            self.syntax_msg = "syntax Error\n" + e.stdout  # Store error information in syntax_msg

        # print(self.syntax_msg)


if __name__ == "__main__":
    checker = SyntaxChecker()
    checker.run()
 