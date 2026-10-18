import ast
import logging
from pathlib import Path
import tempfile
from types import SimpleNamespace
import unittest
from unittest.mock import patch

from specification_verify import SpecVerifier


SEP = '------------------------------------------------------------'


def goal(title, status='Valid'):
    return f'\n{title}\nProver Z3 returns {status}\n'


def final_valid(verifier):
    # Exercise the actual final valid expression without loading the LLM stack.
    tree = ast.parse(Path(__file__).with_name('main.py').read_text())
    grade = next(n for n in ast.walk(tree)
                 if isinstance(n, ast.FunctionDef) and n.name == '_grade_with_spec_verifier')
    expr = next(n.value for n in grade.body if isinstance(n, ast.Assign)
                and any(isinstance(t, ast.Name) and t.id == 'valid_' for t in n.targets))
    return eval(compile(ast.Expression(expr), 'main.py', 'eval'), {}, {
        name: getattr(verifier, name) for name in (
            'post_result', 'loop_result', 'instance_result', 'assigns_result',
            'decreases_result')
    })


class DecreasesVerificationTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.source = Path(self.tmp.name) / 'gcd.c'
        self.source.write_text('int gcd(int a, int b) {\nreturn gcd(a-b, b);\n}\n')
        self.verifier = SpecVerifier(SimpleNamespace(output_path=self.tmp.name), logging.getLogger('test'))

    def run_log(self, extra):
        text = SEP.join([
            goal('Goal Post-condition in gcd:'),
            goal('Goal Assigns nothing in gcd:'),
            goal('Goal Instance of Pre-condition in gcd:'),
            goal('Goal Assertion in main2:'),
        ] + extra)
        def syntax_ok(checker, path):
            checker.syntax_msg = 'syntax Correct'
        with patch('specification_verify.SyntaxChecker.run', syntax_ok), \
             patch('specification_verify.subprocess.run', return_value=SimpleNamespace(stdout=text)):
            self.verifier.run('gcd')

    def test_each_unproved_status_blocks_final_valid_and_reports_call_site(self):
        for status in ('Timeout', 'Unknown', 'Failed'):
            with self.subTest(status=status):
                self.run_log([goal('Goal Recursion variant (1/2):\nCall decreases at line 2', status),
                              goal('Goal Recursion variant (2/2):\nCall decreases at line 2')])
                self.assertEqual(self.verifier.decreases_result, [False, True])
                self.assertFalse(final_valid(self.verifier))
                self.assertEqual(len(self.verifier.decreases_error_list), 1)
                error, location, code = self.verifier.decreases_error_list[0]
                self.assertIn(status, error)
                self.assertIn(str(self.source), location)
                self.assertIn('line: 2', location)
                self.assertIn('return gcd(a-b, b);', code)
                self.assertIn(status, self.verifier.log_errors())

    def test_all_proved_recursion_goals_pass(self):
        self.run_log([goal('Goal Recursion variant (1/2):\nCall decreases at line 2'),
                      goal('Goal Recursion variant (2/2):\nCall decreases at line 2')])
        self.assertEqual(self.verifier.decreases_result, [True, True])
        self.assertEqual(self.verifier.decreases_error_list, [])
        self.assertTrue(final_valid(self.verifier))

    def test_nonrecursive_program_has_no_decreases_requirement(self):
        self.run_log([])
        self.assertEqual(self.verifier.decreases_result, [])
        self.assertTrue(final_valid(self.verifier))

    def test_rechecking_clears_previous_decreases_failures(self):
        self.run_log([goal('Goal Recursion variant:\nCall decreases at line 2', 'Timeout')])
        self.assertFalse(final_valid(self.verifier))
        self.run_log([goal('Goal Recursion variant:\nCall decreases at line 2')])
        self.assertEqual(self.verifier.decreases_error_list, [])
        self.assertTrue(final_valid(self.verifier))

    def test_missing_call_location_keeps_failure(self):
        self.run_log([goal('Goal Recursion variant:', 'Unknown')])
        self.assertFalse(final_valid(self.verifier))
        self.assertEqual(self.verifier.decreases_error_list[0][1:], (None, None))


if __name__ == '__main__':
    unittest.main()
