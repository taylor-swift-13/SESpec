int countPairs(int * p, int p_len, int array);

 /*@
     requires p_len >= 0;
     requires p_len == 0 || \valid(p + (0 .. p_len-1));
     assigns \nothing;
     ensures \result == \sum integer i; 0 <= i < p_len-1;
                              \sum integer j; i+1 <= j < p_len;
                                  (p[i] != p[j] ? 1 : 0);
 */
int countPairs(int * p, int p_len, int array) {

		int count = 0;
		int total = p_len;
		/*@
		    loop invariant 0 <= index <= total;
		    loop invariant total == p_len;
		    loop invariant 0 <= count <= (total*(total-1))/2;
		    loop invariant count == \sum integer ii; 0 <= ii < index;
		                                 \sum integer jj; ii+1 <= jj < total;
		                                     (p[ii] != p[jj] ? 1 : 0);
		    loop assigns index, count;
		    loop variant total - index;
		*/
		for (int index = 0; index < total - 1; index++) {
			/*@
			    loop invariant index+1 <= c <= total;
			    loop invariant total == p_len;
			    loop invariant 0 <= count <= (total*(total-1))/2;
			    loop invariant count == \sum integer ii; 0 <= ii < index;
			                                 \sum integer jj; ii+1 <= jj < total;
			                                     (p[ii] != p[jj] ? 1 : 0)
			                          + \sum integer jj; index+1 <= jj < c;
			                                     (p[index] != p[jj] ? 1 : 0);
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
