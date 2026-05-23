
/*@ logic integer count_nondiv(integer l, integer m, integer code) =
      l > m ? 0 :
      ((l % code != 0 ? 1 : 0) + count_nondiv(l + 1, m, code));
*/

/*@
  assigns \nothing;
  ensures (b <= 0 && l > m) ==> \result == -1;
  ensures \result == -1 || (\result >= l && \result <= m);
*/
int foo342(int code, int b, int l, int m) {

		int result = 0;
		
        /*@
          loop invariant 0 <= result;
          loop invariant result <= c - l;
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
