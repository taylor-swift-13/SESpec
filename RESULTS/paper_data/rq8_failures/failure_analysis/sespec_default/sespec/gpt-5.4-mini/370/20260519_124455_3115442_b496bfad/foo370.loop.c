
/*@
  logic integer foo370_result(integer c, integer k, integer z) =
    (c % k) == z ? c : 0;
*/

int foo370(int value, int k, int z) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant c >= 1;
          loop invariant z == \at(z,Pre);
          loop invariant k == \at(k,Pre);
          loop invariant value == \at(value,Pre);
          loop invariant result == 0 || (1 <= result < c && (result % k) == z);
          loop assigns c, result;
            */
            for (int c = 1; c <= value; c++) {
			if ((c % k) == z) {
				result = c;
			}
		}
            
		return result;
}
