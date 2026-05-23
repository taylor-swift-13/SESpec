
/*@
  assigns \nothing;
  ensures \result == binom_iter(seed, (\old(m) > seed - \old(m) ? seed - \old(m) : \old(m)));
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
