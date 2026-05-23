
/*@
  logic integer cube_sum(integer n) =
    n <= 0 ? 0 : cube_sum(n - 1) + n * n * n;
*/

/*@ 
  logic integer tri_sum(integer n) =
    n <= 0 ? 0 : tri_sum(n - 1) + n;
*/

/*@
  requires diff >= 0;
*/
int foo330(int diff) {

		int result = 0;
		int max = 0;
		
        /*@
          loop invariant 1 <= j <= diff + 1;
          loop invariant max == 0;
          loop invariant diff == \at(diff,Pre);
          loop invariant result >= 0;
          loop invariant result == cube_sum(j - 1);
          loop assigns j, result;
        */
        for (int j = 1; j <= diff; j++) {
			result += j * j * j;
		}
            
		
            
        /*@
          loop invariant 1 <= j <= diff + 1;
          loop invariant diff == \at(diff,Pre);
          loop invariant 0 <= max;
          loop invariant max == tri_sum(j - 1);
          loop assigns j, max;
        */
        for (int j = 1; j <= diff; j++) {
			max += j;
		}
            
		return result - max;
}
