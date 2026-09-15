
/*@ predicate PLACE_HOLDER_result(int c, int result, int z, int k, int value) =
      result == 0 || (result <= value && (result % k) == z);
*/

int foo276(int value, int k, int z) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant result == 0 || (result <= value && (result % k) == z);
          loop invariant z == \at(z,Pre);
          loop invariant k == \at(k,Pre);
          loop invariant value == \at(value,Pre);
          loop assigns c, result;
            */
            for (int c = 1; c <= value; c++) {
			if ((c % k) == z) {
				result = c;
			}
		}
            
		return result;
}
