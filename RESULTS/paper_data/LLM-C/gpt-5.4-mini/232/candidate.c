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
		    loop invariant 0 <= index <= total - 1 || index == total - 1 || total <= 1;
		    loop invariant 0 <= count;
		    loop assigns index, count;
		    loop variant total - 1 - index;
		*/
		for (int index = 0; index < total - 1; index++) {
			/*@
			    loop invariant index + 1 <= c <= total;
			    loop invariant 0 <= count;
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
