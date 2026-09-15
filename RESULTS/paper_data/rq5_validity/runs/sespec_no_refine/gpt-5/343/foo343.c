
/*@
  ensures (\result == -1 ==> count_not_divisible(l, c, code) != b);
  ensures (\result != -1 ==> l <= \result <= c && count_not_divisible(l, \result, code) == b);
  assigns \nothing;
*/
int foo343(int code, int b, int l, int c) {

		int ret = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant ret == count_not_divisible(l, loop - 1, code);
          loop invariant 0 <= ret;
          loop invariant (loop >= l) ==> (ret <= (loop - l));
          loop invariant (loop <= \at(c,Pre)) ==> (ret + (((loop % code) != 0) ? 1 : 0) == count_not_divisible(l, loop, code));
          loop invariant (loop <= \at(c,Pre)) ==> (ret <= (loop - \at(l,Pre)));
          loop invariant c == \at(c,Pre);
          loop invariant l == \at(l,Pre);
          loop invariant b == \at(b,Pre);
          loop invariant code == \at(code,Pre);
          loop assigns loop, ret;
            */
            for (int loop = l; loop <= c; loop++) {
			if (loop % code != 0) {
				ret++;
			}
			if (ret == b) {
				return loop;
			}
		}
            
		return -1;
}
