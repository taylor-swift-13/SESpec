
/*@
  logic integer binom_iter(integer n, integer k) =
    (k <= 0) ? 1 :
    (k > n) ? 0 :
    (k == 1) ? n :
    (binom_iter(n, k - 1) * (n - (k - 1) + 1)) / k;
*/

int foo376(int seed, int m) {

		if (m > seed - m)
			m = seed - m;
		int b = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant seed == \at(seed,Pre);
          loop invariant seed == \at(seed,Pre);
          loop assigns r, b;
            */
            for (int r = 1; r <= m; r++) {
			b = b * (seed - r + 1) / r;
		}
            
		return b;
}
