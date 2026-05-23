
        /*@
        logic integer P(integer seed, integer n) =
          (n <= 0 ? 1 : P(seed, n - 1) * (seed - n + 1) / n);
        */
        
int foo376(int seed, int m) {

		if (m > seed - m)
			m = seed - m;
		int b = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant r >= 1;
          loop invariant b == P(seed, r - 1);
          loop assigns b, r;
            */
            for (int r = 1; r <= m; r++) {
			b = b * (seed - r + 1) / r;
		}
            
		return b;
}
