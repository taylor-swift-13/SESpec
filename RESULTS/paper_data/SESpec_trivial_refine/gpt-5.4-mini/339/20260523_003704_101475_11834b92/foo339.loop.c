
        /*@
        logic integer count_divisors(integer n) =
          \numof integer k; 1 <= k <= n && num % k == 0;
        */
        
int foo339(int num, int z) {

		if (z < 0) {
			z = -z;
		}
		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index <= z + 1;
          loop invariant 0 <= result <= index - 1;
          loop invariant result == \numof integer k; 1 <= k < index && num % k == 0;
          loop assigns index, result;
            */
            for (int index = 1; index <= z; index++) {
			if (num % index == 0) {
				result = result + 1;
			}
		}
            
		return result;
}
