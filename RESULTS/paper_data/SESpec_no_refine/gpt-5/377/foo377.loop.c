
/*@
  logic integer binom(integer n, integer k) =
    (k < 0 || k > n) ? 0 :
    (k == 0 || k == n) ? 1 :
    binom(n - 1, k - 1) + binom(n - 1, k);
*/

int foo377(int seed, int p) {

		if (p > seed - p)
			p = seed - p;
		int b = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant seed == seed;
          loop invariant p == p;
          loop assigns r, b;
            */
            for (int r = 1; r <= p; r++) {
			b = b * (seed - r + 1) / r;
		}
            
		return b;
}
