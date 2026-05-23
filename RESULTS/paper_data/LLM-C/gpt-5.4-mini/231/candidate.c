/*@
    requires p_len >= 0;
    requires p_len == 0 || \valid_read(p + (0..p_len-1));
    assigns \nothing;
    ensures \result >= 0;
*/
int countPairs(int * p, int p_len, int array);

 /*@
    requires p_len >= 0;
    requires p_len == 0 || \valid_read(p + (0..p_len-1));
    assigns \nothing;
    ensures \result >= 0;
*/
int countPairs(int * p, int p_len, int array) {

		int count = 0;
		int total = p_len;
		/*@
		    loop invariant 0 <= index <= total - 1 || (total <= 1 && index == 0);
		    loop invariant 0 <= count;
		    loop assigns index, c, count;
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
				if (p[index] != p[c]) {
					count++;
				}
			}
		}
		return count;
}
