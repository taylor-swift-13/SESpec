int countPairs(int * pairs, int pairs_len, int array);

/*@
    requires pairs_len >= 0;
    requires pairs_len == 0 || \valid_read(pairs + (0 .. pairs_len-1));
    assigns \nothing;
    ensures \result == \sum integer i; 0 <= i < pairs_len;
                        \sum integer j; i < j < pairs_len;
                            (pairs[i] != pairs[j]) ? 1 : 0;
*/
int countPairs(int * pairs, int pairs_len, int array) {

		int count = 0;
		int total = pairs_len;
		/*@
		    loop invariant 0 <= index <= total;
		    loop invariant total == pairs_len;
		    loop invariant count == \sum integer i; 0 <= i < index;
		                                \sum integer j; i < j < total;
		                                    (pairs[i] != pairs[j]) ? 1 : 0;
		    loop assigns index, count;
		    loop variant total - index;
		*/
		for (int index = 0; index < total - 1; index++) {
			/*@
			    loop invariant index + 1 <= c <= total;
			    loop invariant count == \sum integer i; 0 <= i < index;
			                                    \sum integer j; i < j < total;
			                                        (pairs[i] != pairs[j]) ? 1 : 0
			                        + \sum integer j; index + 1 <= j < c;
			                                    (pairs[index] != pairs[j]) ? 1 : 0;
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
