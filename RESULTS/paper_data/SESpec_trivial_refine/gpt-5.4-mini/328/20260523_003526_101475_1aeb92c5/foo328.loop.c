
        /*@
        logic integer sum_cubes(integer n) =
            n <= 0 ? 0 : sum_cubes(n - 1) + n * n * n;

        logic integer sum_upto(integer n) =
            n <= 0 ? 0 : sum_upto(n - 1) + n;
        */
        
/*@
        logic integer sum_cubes(integer n) =
            n <= 0 ? 0 : sum_cubes(n - 1) + n * n * n;

        logic integer sum_upto(integer n) =
            n <= 0 ? 0 : sum_upto(n - 1) + n;
        */
        

int foo328(int diff) {

		int result = 0;
		int max = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant result == sum_cubes(c - 1);
          loop invariant c >= 1;
          loop assigns c, result;
            */
            for (int c = 1; c <= diff; c++) {
			result += c * c * c;
		}
            
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant max == sum_upto(c - 1);
          loop invariant c >= 1;
          loop assigns c, max;
            */
            for (int c = 1; c <= diff; c++) {
			max += c;
		}
            
		return result - max;
}
