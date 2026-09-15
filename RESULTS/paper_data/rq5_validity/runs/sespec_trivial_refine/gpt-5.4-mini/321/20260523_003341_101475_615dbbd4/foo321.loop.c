
/*@
predicate divides(integer d, integer x) = d != 0 && x % d == 0;
*/

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
          loop invariant 1 <= l;
          loop invariant n >= 0 ==> l <= n + 1;
          loop invariant 1 <= ret <= l;
          loop invariant divides(ret, n) && divides(ret, y);
          loop invariant \forall integer k; 1 <= k < l && divides(k, n) && divides(k, y) ==> k <= ret;
          loop assigns ret, l;
            */
            for (int l = 1; l <= n; l++) {
			if (n % l == 0 && y % l == 0) {
				ret = l;
			}
		}
            
		r = (n * y) / ret;
		return r;
}
