/*@ 
  logic integer count_j(int *a, integer i, integer j, integer n, integer p) =
    j >= n ? 0 :
      ((a[i] + a[j] == p) ? 1 : 0) + count_j(a, i, j + 1, n, p);

  logic integer count_i_range(int *a, integer i, integer i_end, integer n, integer p) =
    i >= i_end ? 0 :
      count_j(a, i, i + 1, n, p) + count_i_range(a, i + 1, i_end, n, p);
*/

int getPairsCount(int * pairs, int pairs_len, int num, int p);

 /*@
   requires pairs_len >= 0;
   requires 0 <= num <= pairs_len;
   requires \valid_read(pairs + (0..pairs_len-1));
   assigns \nothing;
   ensures \result == count_i_range(pairs, 0, num, num, p);
 */
int getPairsCount(int * pairs, int pairs_len, int num, int p) {

		int result = 0;
		/*@ 
		  loop invariant 0 <= index <= num;
		  loop invariant result == count_i_range(pairs, 0, index, num, p);
		  loop assigns index, result;
		  loop variant num - index;
		*/
		for (int index = 0; index < num; index++) {
			/*@
			  loop invariant index + 1 <= j <= num;
			  loop invariant result ==
			     count_i_range(pairs, 0, index, num, p)
			     + count_j(pairs, index, index + 1, j, num, p);
			  loop assigns j, result;
			  loop variant num - j;
			*/
			for (int j = index + 1; j < num; j++) {
				if (pairs[index] + pairs[j] == p) {
					result++;
				}
			}
		}
		return result;
}
