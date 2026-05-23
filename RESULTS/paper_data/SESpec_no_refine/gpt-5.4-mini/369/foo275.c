
/*@
  assigns \nothing;
*/
int foo275(int value, int p, int dy) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant dy == \at(dy,Pre);
          loop invariant p == \at(p,Pre);
          loop invariant value == \at(value,Pre);
          loop assigns c, result;
            */
            for (int c = 1; c <= value; c++) {
			if ((c % p) == dy) {
				result = c;
			}
		}
            
		return result;
}
