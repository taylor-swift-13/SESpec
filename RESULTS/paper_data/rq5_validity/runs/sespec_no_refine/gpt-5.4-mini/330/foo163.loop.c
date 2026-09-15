
/*@
  logic integer cube_sum(integer n) =
    n <= 0 ? 0 : cube_sum(n - 1) + n * n * n;

  logic integer tri_sum(integer n) =
    n <= 0 ? 0 : tri_sum(n - 1) + n;
*/

int foo163(int diff) {

		int result = 0;
		int max = 0;
		
            
        /*@
          loop invariant max == 0;
          loop invariant diff == diff;
          loop assigns j, result;
            */
            for (int j = 1; j <= diff; j++) {
			result += j * j * j;
		}
            
		
            
        /*@
          loop invariant max == tri_sum(j - 1);
          loop invariant result == cube_sum(diff);
          loop invariant 1 <= j <= diff + 1;
          loop assigns j, max;
            */
            /*@
          loop invariant (!(j <= diff)) ==> ();
          loop assigns j, max;
            */
            for (int j = 1; j <= diff; j++) {
			max += j;
		}
            
		return result - max;
}
