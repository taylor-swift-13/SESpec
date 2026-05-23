
/*@ logic boolean PLACE_HOLDER_result(integer c, integer k, integer z) = ((c % k) == z); */

int foo276(int value, int k, int z) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
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
