
/*@ logic integer sum_cubes(integer n) =
      n <= 0 ? 0 : sum_cubes(n-1) + n*n*n;
*/

        
/*@
  requires diff >= 0;
  requires \true;
  assigns \nothing;   
  ensures \result == sum_cubes(diff) - (diff*(diff+1))/2; 
  ensures \result == sum_cubes(diff) - (diff*(diff+1))/2;  
*/
int foo162_c329(int diff) {

		int ret = 0;
		int max = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= j <= diff + 1;
          loop invariant ret == sum_cubes(j-1);
          loop invariant diff >= 0;
          loop assigns j, ret;
            */
            for (int j = 1; j <= diff; j++) {
			ret += j * j * j;
		}
            
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= j <= diff + 1;
          loop invariant (j <= diff) ==> (max == (j-1)*(j)/2);
          loop invariant (!(j <= diff)) ==> (max == diff*(diff+1)/2);
          loop assigns j, max;
            */
            for (int j = 1; j <= diff; j++) {
			max += j;
		}
            
		return ret - max;
}
