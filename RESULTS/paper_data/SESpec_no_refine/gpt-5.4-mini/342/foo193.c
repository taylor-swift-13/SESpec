
/*@ 
  assigns \nothing;
  ensures (count_nondiv(code, l, m) >= b) ==> 
            (\result >= l && \result <= m &&
             count_nondiv(code, l, \result) == b &&
             (\result == l || count_nondiv(code, l, \result - 1) < b));
  ensures (count_nondiv(code, l, m) < b) ==> \result == -1;
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
