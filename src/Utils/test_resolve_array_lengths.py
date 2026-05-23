"""Unit tests for `resolve_array_lengths` (Utils/utils.py).

Tests the deterministic layers (name convention + body scan). Layer (c)
(LLM fallback) is exercised with a mock to avoid network calls.

Run with:  python -m pytest src/Utils/test_resolve_array_lengths.py
or         python -m unittest src/Utils/test_resolve_array_lengths.py
"""

from __future__ import annotations

import unittest
from typing import List, Optional

import sys, os
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

from Utils.main_class import Parameter
from Utils.utils import resolve_array_lengths


def _mk(name: str, type_: str = 'int', is_ptr: bool = False,
        ptr_depth: int = 0, array_length=-1) -> Parameter:
    return Parameter(
        name=name,
        type=type_,
        is_ptr=is_ptr,
        ptr_depth=ptr_depth,
        is_struct=False,
        array_length=array_length,
        is_recursive=False,
    )


class TestNameConvention(unittest.TestCase):

    def test_arr_with_arr_len(self):
        params = [
            _mk('arr', 'int', is_ptr=True, ptr_depth=1, array_length='INT_MAX'),
            _mk('arr_len', 'int'),
        ]
        resolve_array_lengths(params, 'void f(int *arr, int arr_len) { arr[0]; }')
        self.assertEqual(params[0].length_expr, 'arr_len')
        self.assertEqual(params[0].length_source, 'name')

    def test_2d_rows_cols(self):
        params = [
            _mk('points', 'int', is_ptr=True, ptr_depth=2, array_length='INT_MAX'),
            _mk('points_len', 'int'),
            _mk('points_rows', 'int'),
            _mk('points_cols', 'int'),
        ]
        resolve_array_lengths(params,
            'void f(int **points, int points_len, int points_rows, int points_cols) { points[0][0]; }')
        # 2D pair wins over 1D suffix.
        self.assertEqual(params[0].length_expr, 'points_rows * points_cols')
        self.assertEqual(params[0].length_dims, ['points_rows', 'points_cols'])
        self.assertEqual(params[0].length_source, 'name')

    def test_n_prefix(self):
        params = [
            _mk('buf', 'int', is_ptr=True, ptr_depth=1, array_length='INT_MAX'),
            _mk('n_buf', 'int'),
        ]
        resolve_array_lengths(params, 'void f(int *buf, int n_buf) { buf[0]; }')
        self.assertEqual(params[0].length_expr, 'n_buf')
        self.assertEqual(params[0].length_source, 'name')


class TestBodyScan(unittest.TestCase):

    def test_mat_mul(self):
        # void mat_mul(int *out, int *A, int *B, int ra, int ca_rb, int cb)
        # out[i * cb + j]   over for(i<ra), for(j<cb)
        # A  [i * ca_rb + k] over for(i<ra), for(k<ca_rb)
        # B  [k * cb + j]    over for(k<ca_rb), for(j<cb)
        code = """
        void mat_mul(int *out, int *A, int *B, int ra, int ca_rb, int cb) {
            for (int i = 0; i < ra; i++) {
                for (int j = 0; j < cb; j++) {
                    int s = 0;
                    for (int k = 0; k < ca_rb; k++) {
                        s = s + A[i * ca_rb + k] * B[k * cb + j];
                    }
                    out[i * cb + j] = s;
                }
            }
        }
        """
        params = [
            _mk('out', 'int', is_ptr=True, ptr_depth=1, array_length='INT_MAX'),
            _mk('A', 'int', is_ptr=True, ptr_depth=1, array_length='INT_MAX'),
            _mk('B', 'int', is_ptr=True, ptr_depth=1, array_length='INT_MAX'),
            _mk('ra', 'int'),
            _mk('ca_rb', 'int'),
            _mk('cb', 'int'),
        ]
        resolve_array_lengths(params, code, function_name='mat_mul')
        # out is indexed by `i * cb + j` with i<ra, j<cb → length = ra * cb
        self.assertEqual(params[0].length_expr, 'ra * cb')
        self.assertEqual(params[0].length_dims, ['ra', 'cb'])
        self.assertEqual(params[0].length_source, 'body')
        # A is indexed by `i * ca_rb + k` with i<ra, k<ca_rb → ra * ca_rb
        self.assertEqual(params[1].length_expr, 'ra * ca_rb')
        self.assertEqual(params[1].length_source, 'body')
        # B is indexed by `k * cb + j` with k<ca_rb, j<cb → ca_rb * cb
        self.assertEqual(params[2].length_expr, 'ca_rb * cb')
        self.assertEqual(params[2].length_source, 'body')

    def test_two_pointers_one_length(self):
        # void f(int *a, int *b, int n)  with a[i] and b[i] over for(i<n)
        code = """
        void f(int *a, int *b, int n) {
            for (int i = 0; i < n; i++) {
                b[i] = a[i] + 1;
            }
        }
        """
        params = [
            _mk('a', 'int', is_ptr=True, ptr_depth=1, array_length='INT_MAX'),
            _mk('b', 'int', is_ptr=True, ptr_depth=1, array_length='INT_MAX'),
            _mk('n', 'int'),
        ]
        resolve_array_lengths(params, code, function_name='f')
        self.assertEqual(params[0].length_expr, 'n')
        self.assertEqual(params[0].length_source, 'body')
        self.assertEqual(params[1].length_expr, 'n')
        self.assertEqual(params[1].length_source, 'body')


class TestNoIndexing(unittest.TestCase):

    def test_pointer_unused(self):
        code = 'void f(int *p) { (void)p; }'
        params = [_mk('p', 'int', is_ptr=True, ptr_depth=1, array_length=-1)]
        resolve_array_lengths(params, code, function_name='f')
        # array_length stayed -1 (no indexing), so resolver shouldn't fire.
        self.assertIsNone(params[0].length_expr)
        self.assertEqual(params[0].length_source, 'none')


class TestLLMFallback(unittest.TestCase):

    class _MockLLM:
        def __init__(self, return_value: Optional[str]):
            self.return_value = return_value
            self.calls = 0

        def chat(self, messages):
            self.calls += 1
            if self.return_value is None:
                return '{"length_expr": null, "reason": "unsure"}'
            return f'{{"length_expr": "{self.return_value}", "reason": "ok"}}'

    def test_layer_c_picks_up_when_a_b_miss(self):
        # Local intermediate variable hides the bound from layer (b).
        code = """
        void f(int *p, int sz) {
            int len = sz - 1;
            for (int i = 0; i < len; i++) p[i] = 0;
        }
        """
        params = [
            _mk('p', 'int', is_ptr=True, ptr_depth=1, array_length='INT_MAX'),
            _mk('sz', 'int'),
        ]
        llm = self._MockLLM(return_value='sz - 1')
        resolve_array_lengths(params, code, function_name='f', llm=llm)
        # layer (b) misses (the loop bound is `len`, a local), layer (c)
        # supplies the length from the LLM mock.
        self.assertEqual(llm.calls, 1)
        self.assertEqual(params[0].length_expr, 'sz - 1')
        self.assertEqual(params[0].length_source, 'llm')

    def test_layer_c_rejects_unsafe_expr(self):
        code = 'void f(int *p, int sz) { p[0]; }'
        params = [
            _mk('p', 'int', is_ptr=True, ptr_depth=1, array_length='INT_MAX'),
            _mk('sz', 'int'),
        ]
        llm = self._MockLLM(return_value='sizeof(p) / sizeof(*p)')
        resolve_array_lengths(params, code, function_name='f', llm=llm)
        # `sizeof` not in safe expression alphabet → rejected.
        self.assertIsNone(params[0].length_expr)
        self.assertEqual(params[0].length_source, 'none')

    def test_layer_c_rejects_null(self):
        code = 'void f(int *p) { p[0]; }'
        params = [_mk('p', 'int', is_ptr=True, ptr_depth=1, array_length='INT_MAX')]
        llm = self._MockLLM(return_value=None)  # → returns "null"
        resolve_array_lengths(params, code, function_name='f', llm=llm)
        self.assertIsNone(params[0].length_expr)
        self.assertEqual(params[0].length_source, 'none')

    def test_layer_c_cache(self):
        code = 'void f(int *p, int sz) { int len = sz; for (int i = 0; i < len; i++) p[i] = 0; }'
        params = [
            _mk('p', 'int', is_ptr=True, ptr_depth=1, array_length='INT_MAX'),
            _mk('sz', 'int'),
        ]
        llm = self._MockLLM(return_value='sz')
        cache: dict = {}
        # First call invokes the mock.
        resolve_array_lengths(params, code, function_name='f', llm=llm, llm_cache=cache)
        self.assertEqual(llm.calls, 1)
        self.assertEqual(cache[('f', 'p')], 'sz')
        # Reset param state and re-resolve — the cache should short-circuit.
        params[0].length_expr = None
        params[0].length_source = 'none'
        resolve_array_lengths(params, code, function_name='f', llm=llm, llm_cache=cache)
        self.assertEqual(llm.calls, 1)  # NOT 2 — cached
        self.assertEqual(params[0].length_expr, 'sz')


if __name__ == '__main__':
    unittest.main()
