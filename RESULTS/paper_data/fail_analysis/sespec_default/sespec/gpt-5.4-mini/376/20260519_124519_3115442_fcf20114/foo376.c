
/*@
  assigns \nothing;
*/
int foo376(int seed, int m) {

		if (m > seed - m)
			m = seed - m;
		int b = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant seed == \at(seed,Pre);
          loop invariant m == \at(m,Pre) || m == \at(seed,Pre) - \at(m,Pre);
          loop assigns r, b;
            */
            for (int r = 1; r <= m; r++) {
			b = b * (seed - r + 1) / r;
		}
            
		return b;
}
