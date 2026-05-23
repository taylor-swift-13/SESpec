
/*@
  logic integer sum4(integer n) =
    (n <= 0) ? 0 : n*n*n*n + sum4(n - 1);
*/

int foo321_c395(int p) {

		int odd = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant c >= 1;
          loop invariant odd == 16 * sum4(c - 1);
          loop invariant p == \at(p,Pre);
          loop assigns c, odd;
            */
            for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			odd = odd + (tmp * tmp * tmp * tmp);
		}
            
		return odd;
}
