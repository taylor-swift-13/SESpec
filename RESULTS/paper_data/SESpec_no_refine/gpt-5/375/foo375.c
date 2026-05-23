
/*@
  assigns \nothing;
  ensures \result == binom_step(num, (p > num - p ? num - p : p));
*/
int foo375(int num, int p) {

		if (p > num - p)
			p = num - p;
		int b = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant num == \at(num,Pre);
          loop assigns r, b;
            */
            for (int r = 1; r <= p; r++) {
			b = b * (num - r + 1) / r;
		}
            
		return b;
}
