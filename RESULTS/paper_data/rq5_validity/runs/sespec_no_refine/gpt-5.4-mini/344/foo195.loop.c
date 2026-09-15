
/*@
  logic integer count_nondiv(integer l, integer c, integer code) =
    c < l ? 0 :
    ((c % code) != 0 ? 1 : 0) + count_nondiv(l, c - 1, code);
*/

int foo195(int code, int b, int l, int m) {

		int ret = 0;
		
            
        /*@
          loop invariant l <= c <= m + 1;
          loop invariant m == \at(m,Pre);
          loop invariant l == \at(l,Pre);
          loop invariant b == \at(b,Pre);
          loop invariant code == \at(code,Pre);
          loop invariant ret == count_nondiv(l, c - 1, code);
        */
            /*@
          loop invariant (c <= \at(m,Pre)) ==> (ret == count_nondiv(l, c - 1, code)) ;
          loop invariant (!(c <= \at(m,Pre))) ==> ((ret == 0)&&(m == \at(m,Pre))&&(l == \at(l,Pre))&&(b == \at(b,Pre))&&(code == \at(code,Pre)));
          loop invariant m == \at(m,Pre);
          loop invariant l == \at(l,Pre);
          loop invariant b == \at(b,Pre);
          loop invariant code == \at(code,Pre);
          loop assigns c, ret;
            */
            for (int c = l; c <= m; c++) {
			if (c % code != 0) {
				ret++;
			}
			if (ret == b) {
				return c;
			}
		}
            
		return -1;
}
