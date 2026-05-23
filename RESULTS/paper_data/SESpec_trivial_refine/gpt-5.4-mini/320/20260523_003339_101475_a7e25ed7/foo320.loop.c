
/*@
*/

/*@ 
  loop invariant 1 <= l <= n + 1;
  loop assigns l, ret;
  loop invariant ret >= 1;
  loop invariant n % ret == 0 && y % ret == 0;
*/
int foo320(int n, int y) {

		int ret = 1;
		int g = 1;
		if (n > y) {
			int r = n;
			n = y;
			y = r;
		}
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= l <= n + 1;
          loop invariant ret >= 1;
          loop invariant n % ret == 0 && y % ret == 0;
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
