
/*@ 
  logic integer sum_cubes(integer n) =
    n <= 0 ? 0 : sum_cubes(n-1) + n*n*n;
*/

/*@
  requires \true;
  assigns \nothing;
  ensures \true;
*/

int foo163_c330(int diff) {

		int result = 0;
		int max = 0;
		
            
        /*@
          loop invariant max == 0;
          loop invariant diff == \at(diff,Pre);
          loop assigns j, result;
            */
            for (int j = 1; j <= diff; j++) {
			result += j * j * j;
		}
            
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (j <= diff) ==> (max == (j-1) * j / 2);
          loop assigns j, max;
            */
            for (int j = 1; j <= diff; j++) {
			max += j;
		}
            
		return result - max;
}
