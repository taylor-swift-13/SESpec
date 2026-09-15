
        /*@
        */
        
int foo341(int num, int z) {

		if (z < 0) {
			z = -z;
		}
		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= loop <= z + 1;
          loop invariant result == \numof(int i; 1 <= i < loop && num % i == 0);
          loop assigns loop, result;
            */
            for (int loop = 1; loop <= z; loop++) {
			if (num % loop == 0) {
				result = result + 1;
			}
		}
            
		return result;
}
