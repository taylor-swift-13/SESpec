
/*@
  logic integer fourth_power(integer x) = x * x * x * x;
*/

int foo395(int p) {

		int odd = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant p == \at(p,Pre);
          loop invariant 0 <= odd;
          */
            for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			odd = odd + (tmp * tmp * tmp * tmp);
		}
            
		return odd;
}
