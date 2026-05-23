
/*@
  requires \true;
  assigns \nothing;
  ensures
    (count_not_div(code, l, m) >= b) ==>
      \result >= l &&
      \result <= m &&
      count_not_div(code, l, \result) == b &&
      (\result == l ? \true : count_not_div(code, l, \result - 1) == b - 1);
  ensures
    (count_not_div(code, l, m) < b) ==> \result == -1;
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
