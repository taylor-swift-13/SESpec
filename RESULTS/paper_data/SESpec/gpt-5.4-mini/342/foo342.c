
/*@
  logic integer count_nondiv(integer code, integer l, integer u) =
    u < l ? 0 :
    count_nondiv(code, l, u - 1) + ((u % code != 0) ? 1 : 0);
*/

int foo342(int code, int b, int l, int m) {

		int result = 0;
		
        /*@
          loop invariant c >= l;
          loop invariant 0 <= result;
          loop invariant result == count_nondiv(code, l, c - 1);
          loop invariant 0 <= result <= c - l;
          loop invariant result == 0 || (\exists integer i; l <= i < c && i % code != 0);
          loop invariant m == \at(m,Pre);
          loop invariant l == \at(l,Pre);
          loop invariant b == \at(b,Pre);
          loop invariant code == \at(code,Pre);
          loop invariant (c > m) ==> (result == count_nondiv(code, l, m));
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
