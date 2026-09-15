
/*@
  logic boolean PLACE_HOLDER_ret(integer j, integer n, integer y, integer ret) =
    (j <= y) ==> (ret == 1);
*/

int foo135(int n, int y) {

		int ret = 1;
		int l = 1;
		if (n > y) {
			int g = n;
			n = y;
			y = g;
		}
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (j <= \at(y,Pre)) ==> (((l == 1)&&(ret == 1)&&(y == \at(n,Pre))&&(n == \at(y,Pre))) || (PLACE_HOLDER_ret(j, n, y, ret)));
          loop invariant (!(j <= \at(y,Pre))) ==> ((l == 1)&&(ret == 1)&&(y == \at(n,Pre))&&(n == \at(y,Pre)));
          loop invariant l == 1;
          loop invariant y == \at(n,Pre);
          loop invariant n == \at(y,Pre);
          loop assigns j, ret;
            */
            for (int j = 1; j <= n; j++) {
			if (n % j == 0 && y % j == 0) {
				ret = j;
			}
		}
            
		l = (n * y) / ret;
		return l;
}
