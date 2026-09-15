
/*@ logic integer div_count(integer n, integer z) =
      z <= 0 ? 0 : div_count(n, z - 1) + ((n % z == 0) ? 1 : 0); */
/*@ 
  assigns \nothing;
*/
int foo190(int num, int z) {

		if (z < 0) {
			z = -z;
		}
		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
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
