
/*@
  logic integer div_lower_bound(integer n, integer y, integer l) =
    l <= y;
*/

int foo136(int n, int y) {

		int ret = 1;
		int g = 1;
		if (n > y) {
			int r = n;
			n = y;
			y = r;
		}
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (l <= \at(y,Pre)) ==> (((g == 1)&&(ret == 1)&&(y == \at(n,Pre))&&(n == \at(y,Pre))) || (ret >= 1));
          loop invariant (!(l <= \at(y,Pre))) ==> ((g == 1)&&(ret == 1)&&(y == \at(n,Pre))&&(n == \at(y,Pre)));
          loop invariant g == 1;
          loop invariant y == \at(n,Pre);
          loop invariant n == \at(y,Pre);
          loop assigns l, ret;
            */
            for (int l = 1; l <= n; l++) {
			if (n % l == 0 && y % l == 0) {
				ret = l;
			}
		}
            
		g = (n * y) / ret;
		return g;
}
