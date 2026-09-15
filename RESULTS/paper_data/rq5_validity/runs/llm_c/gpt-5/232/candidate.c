int countPairs(int * pairs, int pairs_len, int array);

/*@ 
  logic integer neq_with_first_upto{L}(int* a, integer first, integer upto) =
    (upto <= first + 1 ? 0 :
      neq_with_first_upto{L}(a, first, upto - 1) + ((a[first] != a[upto - 1]) ? 1 : 0));

  logic integer count_pairs_from_prefix{L}(int* a, integer n, integer idx) =
    (idx <= 0 ? 0 :
      count_pairs_from_prefix{L}(a, n, idx - 1) + neq_with_first_upto{L}(a, idx - 1, n));

  logic integer diff_pairs{L}(int* a, integer n) = count_pairs_from_prefix{L}(a, n, n);
*/

/*@
  requires pairs_len >= 0;
  requires pairs_len == 0 || \valid_read(pairs + (0 .. pairs_len - 1));
  assigns \nothing;
  ensures \result == diff_pairs{Pre}(pairs, pairs_len);
  ensures 0 <= \result;
*/
int countPairs(int * pairs, int pairs_len, int array) {

		int count = 0;
		int total = pairs_len;
		/*@
		  loop invariant 0 <= index <= total;
		  loop invariant count == count_pairs_from_prefix{Pre}(pairs, total, index);
		  loop assigns index, count, c;
		  loop variant total - index;
		*/
		for (int index = 0; index < total - 1; index++) {
			/*@
			  loop invariant index + 1 <= c <= total;
			  loop invariant count == count_pairs_from_prefix{Pre}(pairs, total, index)
			                       + neq_with_first_upto{Pre}(pairs, index, c);
			  loop assigns c, count;
			  loop variant total - c;
			*/
			for (int c = index + 1; c < total; c++) {
				if (pairs[index] != pairs[c]) {
					count++;
				}
			}
		}
		return count;
}
