
int foo190(int num, int z) {

		if (z < 0) {
			z = -z;
		}
		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (index <= \at(z,Pre)) ==> (PLACE_HOLDER_result) ;
          loop invariant (!(index <= \at(z,Pre))) ==> ((result == 0)&&(z == \at(z,Pre))&&(num == \at(num,Pre)));
          loop invariant z == \at(z,Pre);
          loop invariant num == \at(num,Pre);
          loop assigns index, result;
            */
            for (int index = 1; index <= z; index++) {
			if (num % index == 0) {
				result = result + 1;
			}
		}
            
		return result;
}
