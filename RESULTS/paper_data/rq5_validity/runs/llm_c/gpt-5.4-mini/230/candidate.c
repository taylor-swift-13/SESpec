/*@
    requires pairs_len >= 0;
    requires pairs_len == 0 || \valid_read(pairs + (0 .. pairs_len - 1));
    assigns \nothing;
    ensures \result >= 0;
*/
int countPairs(int * pairs, int pairs_len, int array);

 /*@
    requires pairs_len >= 0;
    requires pairs_len == 0 || \valid_read(pairs + (0 .. pairs_len - 1));
    assigns \nothing;
    ensures \result >= 0;
*/
int countPairs(int * pairs, int pairs_len, int array) {

		int count = 0;
		int total = pairs_len;
		/*@
		    loop invariant 0 <= index <= total - 1;
		    loop invariant count >= 0;
		    loop assigns index, count;
		    loop variant total - 1 - index;
		*/
		for (int index = 0; index < total - 1; index++) {
			/*@
			    loop invariant index + 1 <= k <= total;
			    loop invariant count >= 0;
			    loop assigns k, count;
			    loop variant total - k;
			*/
			for (int k = index + 1; k < total; k++) {
				if (pairs[index] != pairs[k]) {
					count++;
				}
			}
		}
		return count;
}
