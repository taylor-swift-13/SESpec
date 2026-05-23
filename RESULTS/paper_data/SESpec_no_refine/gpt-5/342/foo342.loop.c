
/*@
  logic integer count_not_div(integer code, integer lo, integer hi) =
    (hi < lo) ? 0 :
    ((lo % code != 0) ? 1 : 0) + count_not_div(code, lo + 1, hi);
*/

int foo342(int code, int b, int l, int m) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant m == \at(m,Pre);
          loop invariant l == \at(l,Pre);
          loop invariant b == \at(b,Pre);
          loop invariant code == \at(code,Pre);
          loop assigns c, result;
            */
            for (int c = l; c <= m; c++) {
			if (c % code != 0) {
				result++;
			}
			if (result == b) {
				return c;
			}
		}
            
		return -1;
}
