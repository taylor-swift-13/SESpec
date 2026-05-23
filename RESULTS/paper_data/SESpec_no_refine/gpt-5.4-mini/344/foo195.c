
/*@
  assigns \nothing;
  ensures (\result == -1) ==> (\forall integer i; l <= i <= m ==> ((i % code) == 0 || count_nondiv(l, i, code) < b));
  ensures (\result != -1) ==> (l <= \result <= m && count_nondiv(l, \result, code) == b && (\result == l || count_nondiv(l, \result - 1, code) < b));
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
