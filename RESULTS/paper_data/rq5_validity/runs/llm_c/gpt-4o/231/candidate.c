/*@
    requires \valid(p+(0..p_len-1));
    requires p_len >= 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int countPairs(int * p, int p_len, int array);

int countPairs(int * p, int p_len, int array) {

		int count = 0;
		int total = p_len;
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
				if (p[index] != p[c]) {
					count++;
				}
			}
		}
		return count;
}
