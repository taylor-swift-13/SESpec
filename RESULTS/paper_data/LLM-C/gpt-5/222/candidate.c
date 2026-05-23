#include <stddef.h>

int findOddPair(int * arr, int arr_len, int n);

/*@ axiomatic ParityCounting {

  logic integer parity(integer x) = (x % 2 == 0) ? 0 : 1;

  // number of even elements in a[0 .. n-1]
  logic integer count_even{L}(int *a, integer n) =
    (n <= 0) ? 0 :
      count_even(a, n-1) + ((a[n-1] % 2 == 0) ? 1 : 0);

  // number of odd elements in a[0 .. n-1]
  logic integer count_odd{L}(int *a, integer n) =
    (n <= 0) ? 0 :
      count_odd(a, n-1) + ((a[n-1] % 2 != 0) ? 1 : 0);

  // number of indices k in [i+1 .. upto-1] such that (a[i] ^ a[k]) is odd
  logic integer count_diff_with_index{L}(int *a, integer i, integer upto) =
    (upto <= i+1) ? 0 :
      count_diff_with_index(a, i, upto-1)
      + ((((a[i] ^ a[upto-1]) % 2) == 1) ? 1 : 0);

  // number of pairs (p, q) with 0 <= p < q < n, and q < upto counted progressively
  logic integer count_pairs_prefix{L}(int *a, integer upto, integer n) =
    (upto <= 1) ? 0 :
      count_pairs_prefix(a, upto-1, n) + count_diff_with_index(a, upto-1, n);

} */

/*@ requires arr_len >= 0;
    requires arr_len == 0 || \valid_read(arr + (0 .. arr_len-1));
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= (arr_len * (arr_len - 1)) / 2;
    ensures arr_len <= 1 ==> \result == 0;
    ensures \result == count_pairs_prefix(arr, arr_len, arr_len);
    ensures \result == count_even(arr, arr_len) * count_odd(arr, arr_len);
*/
int findOddPair(int * arr, int arr_len, int n) {

		int result = 0;
		int offset = arr_len;
		/*@
      loop invariant 0 <= index <= offset;
      loop invariant result == count_pairs_prefix(arr, index, offset);
      loop assigns index, result;
      loop variant offset - index;
    */
		for (int index = 0; index < offset; index++) {
			/*@
        loop invariant 0 <= index < offset;
        loop invariant index + 1 <= c <= offset;
        loop invariant result == \at(result, LoopEntry) + count_diff_with_index(arr, index, c);
        loop assigns c, result;
        loop variant offset - c;
      */
			for (int c = index + 1; c < offset; c++) {
				if ((arr[index] ^ arr[c]) % 2 == 1) {
					result++;
				}
			}
		}
		return result;
}
