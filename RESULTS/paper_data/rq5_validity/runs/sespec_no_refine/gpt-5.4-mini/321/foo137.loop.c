
/*@
  logic integer PLACE_HOLDER_ret(integer l, integer n, integer y) =
    (l <= n) && (n % l == 0) && (y % l == 0);
*/

int foo137(int n, int y) {

		int ret = 1;
		int r = 1;
		if (n > y) {
			int g = n;
			n = y;
			y = g;
		}
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (l <= \at(y,Pre)) ==> (((r == 1)&&(ret == 1)&&(y == \at(n,Pre))&&(n == \at(y,Pre))) || (PLACE_HOLDER_ret(l, n, y)));
          loop invariant (!(l <= \at(y,Pre))) ==> ((r == 1)&&(ret == 1)&&(y == \at(n,Pre))&&(n == \at(y,Pre)));
          loop invariant r == 1;
          loop invariant y == \at(n,Pre);
          loop invariant n == \at(y,Pre);
          loop assigns l, ret;
            */
            for (int l = 1; l <= n; l++) {
			if (n % l == 0 && y % l == 0) {
				ret = l;
			}
		}
            
		r = (n * y) / ret;
		return r;
}
