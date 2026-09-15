/*@
    requires \valid(pairs+(0..pairs_len-1));
    requires pairs_len >= 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int countPairs(int * pairs, int pairs_len, int array);

int countPairs(int * pairs, int pairs_len, int array) {

		int count = 0;
		int total = pairs_len;
		/*@
		    loop invariant 0 <= index <= total - 1;
		    loop invariant count >= 0;
		    loop assigns index, count;
		    loop variant total - index;
		*/
		for (int index = 0; index < total - 1; index++) {
			/*@
			    loop invariant index + 1 <= c <= total;
			    loop invariant count >= 0;
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
