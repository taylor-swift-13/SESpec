
        /*@ */
        
int foo375(int num, int p) {

		if (p > num - p)
			p = num - p;
		int b = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant b == 1 || b != 0;
          loop invariant r >= 1;
          loop assigns r, b;
            */
            for (int r = 1; r <= p; r++) {
			b = b * (num - r + 1) / r;
		}
            
		return b;
}
