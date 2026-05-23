
/*@
logic integer fact(integer n) = (n <= 1 ? 1 : n * fact(n - 1));
*/
        
int foo377(int seed, int p) {

		if (p > seed - p)
			p = seed - p;
		int b = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= r;
          loop invariant p < 0 || r <= p + 1;
          loop assigns b, r;
            */
            for (int r = 1; r <= p; r++) {
			b = b * (seed - r + 1) / r;
		}
            
		return b;
}
