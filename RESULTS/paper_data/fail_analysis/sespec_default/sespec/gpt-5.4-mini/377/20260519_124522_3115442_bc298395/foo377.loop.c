
/*@
logic integer comb_prod(integer seed, integer r) =
  r <= 1 ? 1 : comb_prod(seed, r - 1) * (seed - r + 1) / r;
*/

int foo377(int seed, int p) {

		if (p > seed - p)
			p = seed - p;
		int b = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant seed == \at(seed,Pre);
          loop invariant p == p;
          loop assigns r, b;
            */
            for (int r = 1; r <= p; r++) {
			b = b * (seed - r + 1) / r;
		}
            
		return b;
}
