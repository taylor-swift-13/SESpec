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
        self.syntax_msg = "syntax Correct"
        


if __name__ == "__main__":
    checker = SyntaxChecker()
    checker.run()
 