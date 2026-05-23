
/*@
  logic integer sum_cubes(integer n) =
    (n <= 0) ? 0 : n*n*n + sum_cubes(n-1);
*/

/*@
  logic integer sum_1_to_n(integer n) =
    (n <= 0) ? 0 : n + sum_1_to_n(n-1);
*/

int foo329(int diff) {

		int ret = 0;
		int max = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant max == 0;
          loop invariant diff == \at(diff,Pre);
          loop assigns j, ret;
            */
            for (int j = 1; j <= diff; j++) {
			ret += j * j * j;
		}
            
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop assigns j, max;
            */
            for (int j = 1; j <= diff; j++) {
			max += j;
		}
            
		return ret - max;
}
