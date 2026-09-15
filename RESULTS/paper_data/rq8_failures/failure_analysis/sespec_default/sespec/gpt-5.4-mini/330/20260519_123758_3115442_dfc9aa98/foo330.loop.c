
/*@
  logic integer sum_cubes(integer n) =
    n <= 0 ? 0 : sum_cubes(n - 1) + n * n * n;
*/

/*@
  logic integer sum_nat(integer n) =
    n <= 0 ? 0 : sum_nat(n - 1) + n;
*/

int foo330(int diff) {

		int result = 0;
		int max = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= j;
          loop invariant diff == \at(diff,Pre);
          loop invariant result == sum_cubes(j - 1);
          loop assigns j, result;
            */
            for (int j = 1; j <= diff; j++) {
			result += j * j * j;
		}
            
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= j;
          loop invariant diff == \at(diff,Pre);
          loop invariant max == sum_nat(j - 1);
          loop assigns j, max;
            */
            for (int j = 1; j <= diff; j++) {
			max += j;
		}
            
		return result - max;
}
