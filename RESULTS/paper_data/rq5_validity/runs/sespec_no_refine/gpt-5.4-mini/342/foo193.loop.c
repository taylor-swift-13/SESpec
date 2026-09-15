
/*@
  logic integer count_nondiv(integer code, integer l, integer c) =
    l > c ? 0 : ((l % code != 0) ? 1 : 0) + count_nondiv(code, l + 1, c);
*/

int foo193(int code, int b, int l, int m) {

		int result = 0;
		
            
        /*@
          loop invariant m == m;
          loop invariant l == l;
          loop invariant b == b;
          loop invariant code == code;
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
