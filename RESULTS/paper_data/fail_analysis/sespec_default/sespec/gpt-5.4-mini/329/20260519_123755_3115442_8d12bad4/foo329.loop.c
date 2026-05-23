
/*@ logic integer sum_cubes(integer n) =
      n <= 0 ? 0 : sum_cubes(n - 1) + n * n * n;
*/

/*@ logic integer sum_n(integer n) =
      n <= 0 ? 0 : sum_n(n - 1) + n;
*/

int foo329(int diff) {

		int ret = 0;
		int max = 0;
		
            /*@
          loop invariant max == 0;
          loop invariant diff == \at(diff,Pre);
          loop assigns j, ret;
            */
            for (int j = 1; j <= diff; j++) {
			ret += j * j * j;
		}
            
            /*@
          loop invariant diff == \at(diff,Pre);
          loop assigns j, max;
            */
            for (int j = 1; j <= diff; j++) {
			max += j;
		}
            
		return ret - max;
}
