"""Unit tests for `SpecGenerator._dedup_function_defs` (spec_gen.py).

Validates that the function-def dedupe pass:
  - keeps the FIRST occurrence per function name,
  - drops subsequent occurrences along with any immediately-preceding
    `/*@ ... */` ACSL contract,
  - leaves single-occurrence functions untouched,
  - does not touch function PROTOTYPES (no body — `T f(...);`).

Run with:  python -m unittest test_spec_gen_dedup
"""

from __future__ import annotations

import os
import sys
import unittest

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

from spec_gen import SpecGenerator


# Helper: dedup is an unbound method that only uses `self` as a method
# receiver (no other instance state). Bind it to a sentinel object so we
# can call it without constructing a full SpecGenerator (which requires
# many dependencies).
_dedup = SpecGenerator._dedup_function_defs.__get__(object(), object)


class TestDedupFunctionDefs(unittest.TestCase):

    def test_single_function_unchanged(self):
        src = (
            "int add(int a, int b) {\n"
            "    return a + b;\n"
            "}\n"
        )
        self.assertEqual(_dedup(src), src)

    def test_two_identical_defs_keeps_first(self):
        src = (
            "int add(int a, int b) {\n"
            "    return a + b;\n"
            "}\n"
            "\n"
            "int add(int a, int b) {\n"
            "    return a + b;\n"
            "}\n"
        )
        out = _dedup(src)
        self.assertEqual(out.count("int add(int a, int b)"), 1)

    def test_drops_subsequent_with_contract(self):
        # The 2nd occurrence has a preceding /*@ ... */ contract — both
        # must be dropped together so we don't leave an orphan contract.
        src = (
            "int add(int a, int b) {\n"
            "    return a + b;\n"
            "}\n"
            "\n"
            "/*@\n"
            "  ensures \\result == a + b;\n"
            "*/\n"
            "int add(int a, int b) {\n"
            "    return a + b;\n"
            "}\n"
        )
        out = _dedup(src)
        self.assertEqual(out.count("int add(int a, int b)"), 1)
        self.assertNotIn("ensures \\result == a + b", out)

    def test_keeps_contract_on_first_occurrence(self):
        src = (
            "/*@\n"
            "  ensures \\result == a + b;\n"
            "*/\n"
            "int add(int a, int b) {\n"
            "    return a + b;\n"
            "}\n"
            "\n"
            "int add(int a, int b) {\n"
            "    return a + b;\n"
            "}\n"
        )
        out = _dedup(src)
        self.assertEqual(out.count("int add(int a, int b)"), 1)
        self.assertIn("ensures \\result == a + b", out)

    def test_three_dupes(self):
        block = "int f(int x) { return x; }\n"
        src = block + "\n" + block + "\n" + block
        out = _dedup(src)
        self.assertEqual(out.count("int f(int x)"), 1)

    def test_distinct_functions_untouched(self):
        src = (
            "int add(int a, int b) {\n"
            "    return a + b;\n"
            "}\n"
            "\n"
            "int mul(int a, int b) {\n"
            "    return a * b;\n"
            "}\n"
        )
        out = _dedup(src)
        self.assertIn("int add(int a, int b)", out)
        self.assertIn("int mul(int a, int b)", out)

    def test_does_not_drop_prototype(self):
        # A prototype is `T name(...);` (no `{`). It is NOT a definition,
        # so the dedupe must not target it, and it must not consume the
        # name slot — the actual definition that follows still gets kept
        # once.
        src = (
            "int compute(int *out, int n);\n"
            "\n"
            "int compute(int *out, int n) {\n"
            "    return out[0] + n;\n"
            "}\n"
            "\n"
            "int compute(int *out, int n) {\n"
            "    return out[0] + n;\n"
            "}\n"
        )
        out = _dedup(src)
        # Prototype kept.
        self.assertIn("int compute(int *out, int n);", out)
        # Exactly one definition kept (one of the two `{` versions).
        self.assertEqual(out.count("return out[0] + n"), 1)

    def test_pointer_return_type(self):
        # Return-type regex must accept `T *` styles.
        src = (
            "int * find(int *arr, int n) {\n"
            "    return arr;\n"
            "}\n"
            "\n"
            "int * find(int *arr, int n) {\n"
            "    return arr;\n"
            "}\n"
        )
        out = _dedup(src)
        self.assertEqual(out.count("int * find(int *arr, int n)"), 1)

    def test_void_return_with_contract(self):
        # Real-world IP_framac shape: void function with multi-line
        # contract, duplicated. Drop the second contract+def cleanly.
        src = (
            "/*@\n"
            "  requires \\valid(out + (0..n-1));\n"
            "  assigns out[0..n-1];\n"
            "*/\n"
            "void zero(int *out, int n) {\n"
            "    for (int i = 0; i < n; i++) out[i] = 0;\n"
            "}\n"
            "\n"
            "/*@\n"
            "  requires \\valid(out + (0..n-1));\n"
            "  assigns out[0..n-1];\n"
            "*/\n"
            "void zero(int *out, int n) {\n"
            "    for (int i = 0; i < n; i++) out[i] = 0;\n"
            "}\n"
        )
        out = _dedup(src)
        self.assertEqual(out.count("void zero(int *out, int n)"), 1)
        # Only ONE copy of the contract survives.
        self.assertEqual(
            out.count("requires \\valid(out + (0..n-1))"), 1
        )

    def test_multiline_helper_chain(self):
        # Pattern matching the actual IP_framac assembly failure:
        # mat_mul appears 4×, triple_fabs_max 2×, plus an entry that
        # references them (and is unique).
        helper_a = (
            "/*@ assigns \\nothing; */\n"
            "int triple_max(int a, int b, int c) {\n"
            "    int m = a; if (b > m) m = b; if (c > m) m = c; return m;\n"
            "}\n"
        )
        helper_b = (
            "/*@ assigns out[0..ra*cb-1]; */\n"
            "void mat_mul(int *out, int *A, int *B, int ra, int cb) {\n"
            "    for (int i = 0; i < ra; i++) for (int j = 0; j < cb; j++) out[i*cb+j] = 0;\n"
            "}\n"
        )
        entry = (
            "void pipeline(int *out) {\n"
            "    mat_mul(out, out, out, 1, 1);\n"
            "    triple_max(1, 2, 3);\n"
            "}\n"
        )
        src = (
            helper_b + "\n" + helper_b + "\n" + helper_a + "\n"
            + helper_b + "\n" + helper_a + "\n" + helper_b + "\n"
            + entry
        )
        out = _dedup(src)
        self.assertEqual(out.count("void mat_mul(int *out, int *A, int *B, int ra, int cb)"), 1)
        self.assertEqual(out.count("int triple_max(int a, int b, int c)"), 1)
        self.assertEqual(out.count("void pipeline(int *out)"), 1)
        # One contract per surviving helper.
        self.assertEqual(out.count("assigns \\nothing"), 1)
        self.assertEqual(out.count("assigns out[0..ra*cb-1]"), 1)


class TestDedupOnRealAssembly(unittest.TestCase):
    """Snapshot test against the actual broken assembly from the IP_framac
    run that triggered ``There is a definition already for triple_fabs_max``.
    No LLM, no Frama-C — purely textual dedupe assertion."""

    BROKEN_FILE = (
        "/home/yangfp/SESpec/src/log/IP_framac/gpt-5.4/"
        "CS_Sts_Gyro_Modify_Single_pipeline/"
        "20260520_162135_4050124_15134c72/3_output/"
        "CS_Sts_Gyro_Modify_Single_pipeline.c"
    )

    def test_no_duplicate_function_defs_after_dedupe(self):
        if not os.path.exists(self.BROKEN_FILE):
            self.skipTest("snapshot file no longer present")
        with open(self.BROKEN_FILE) as f:
            src = f.read()
        out = _dedup(src)
        # The original file had each of these defined 2-4 times.
        for name in ('triple_fabs_max', 'limit_abs', 'mat_mul', 'q_to_C',
                     'q_to_Ksi', 'q_normalize', 'vec_add', 'vec_sub',
                     'vec_scale', 'vec_cross3'):
            # Count opening signatures: `int name(` / `void name(`.
            n_int = out.count(f'int {name}(')
            n_void = out.count(f'void {name}(')
            self.assertLessEqual(n_int + n_void, 1, f'{name} not deduped')


if __name__ == '__main__':
    unittest.main()
