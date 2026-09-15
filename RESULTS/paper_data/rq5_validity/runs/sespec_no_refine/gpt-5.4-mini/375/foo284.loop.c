
/*@
  logic integer binom_step(integer num, integer r) = (num - r + 1) / r;
*/

int foo284(int num, int p) {

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
