
/*@
  logic integer binom_ratio(integer seed, integer r) =
    r <= 0 ? 1 : binom_ratio(seed, r - 1) * (seed - r + 1) / r;
*/

int foo285(int seed, int m) {

		if (m > seed - m)
			m = seed - m;
		int b = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant seed == \at(seed,Pre);
          loop assigns r, b;
            */
            for (int r = 1; r <= m; r++) {
			b = b * (seed - r + 1) / r;
		}
            
		return b;
}
