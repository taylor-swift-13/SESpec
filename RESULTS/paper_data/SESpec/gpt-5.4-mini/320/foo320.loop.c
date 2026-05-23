
/*@
        predicate PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION;
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
          loop invariant 1 <= l;
          loop invariant 1 <= ret <= l;
          loop invariant n <= y;
          loop invariant n % ret == 0 && y % ret == 0;
          loop invariant \forall integer k; 1 <= k < l && n % k == 0 && y % k == 0 ==> k <= ret;
          loop invariant \exists integer k; 1 <= k <= ret && n % k == 0 && y % k == 0;
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
