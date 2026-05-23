
/*@ logic boolean PLACE_HOLDER_result(integer c, integer p, integer z) = (c % p) == z; */

int foo277(int value, int p, int z) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant z == \at(z,Pre);
          loop invariant p == \at(p,Pre);
          loop invariant value == \at(value,Pre);
          loop assigns c, result;
            */
            for (int c = 1; c <= value; c++) {
			if ((c % p) == z) {
				result = c;
			}
		}
            
		return result;
}
