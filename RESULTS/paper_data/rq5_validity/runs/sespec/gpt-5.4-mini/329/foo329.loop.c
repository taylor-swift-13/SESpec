
/*@
  logic integer cube_sum(integer n) =
    n <= 0 ? 0 : cube_sum(n - 1) + n * n * n;
*/

/*@
  logic integer sum_upto(integer n) =
    n <= 0 ? 0 : sum_upto(n - 1) + n;
*/

/*@
  requires diff >= 0;
*/
int foo329(int diff) {

		int ret = 0;
		int max = 0;
		
            
        /*@
          loop invariant 1 <= j <= diff + 1;
          loop invariant ret == cube_sum(j - 1);
          loop invariant ret >= 0;
          loop invariant max == 0;
          loop invariant diff == \at(diff,Pre);
          loop assigns j, ret;
        */
        for (int j = 1; j <= diff; j++) {
			ret += j * j * j;
		}
            
		
            
        /*@
          loop invariant 1 <= j <= diff + 1;
          loop invariant max == sum_upto(j - 1);
          loop invariant 0 <= max;
          loop invariant max <= sum_upto(j - 1);
          loop invariant ret == cube_sum(diff);
          loop invariant diff == \at(diff,Pre);
          loop invariant ret - max == cube_sum(diff) - sum_upto(j - 1);
          loop assigns j, max;
            */
            for (int j = 1; j <= diff; j++) {
			max += j;
		}
            
		return ret - max;
}
