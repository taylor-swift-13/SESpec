
/*@
  logic integer comb(integer n, integer k) =
    k <= 0 ? 1 : comb(n, k - 1) * (n - k + 1) / k;
*/

/*@
  requires 0 <= p <= seed;
  assigns \nothing;
*/
int foo377(int seed, int p) {

		if (p > seed - p)
			p = seed - p;
		int b = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= r <= p + 1;
          loop invariant 0 <= p;
          loop invariant p <= seed - p;
          loop invariant r - 1 <= p;
          loop invariant b == comb(seed, r - 1);
          loop assigns r, b;
            */
            for (int r = 1; r <= p; r++) {
			b = b * (seed - r + 1) / r;
		}
            
		return b;
}
