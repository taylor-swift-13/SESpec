
/*@
logic integer nondiv_count(integer code, integer l, integer u) =
  (u < l ? 0 : nondiv_count(code, l, u - 1) + (u % code != 0 ? 1 : 0));
*/

int foo342(int code, int b, int l, int m) {

		int result = 0;
		
            /*@
          loop invariant result >= 0;
          loop invariant c >= l;
          loop invariant result == nondiv_count(code, l, c - 1);
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
