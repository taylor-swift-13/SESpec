
/*@
  predicate PLACE_HOLDER_VERFICATION_GOAL(integer l, integer n, integer y) =
    l <= y;
*/

/*@ predicate PLACE_HOLDER_ret(integer ret, integer r) = ret == r; */

int foo321(int n, int y) {

		int ret = 1;
		int r = 1;
		if (n > y) {
			int g = n;
			n = y;
			y = g;
		}
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= ret;
          loop invariant ret <= l;
          loop invariant n % ret == 0;
          loop invariant y % ret == 0;
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
