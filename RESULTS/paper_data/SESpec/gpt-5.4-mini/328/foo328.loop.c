
/*@
  logic integer sum_cubes(integer n) =
    n <= 0 ? 0 : sum_cubes(n - 1) + n * n * n;
*/

int foo328(int diff) {

		int result = 0;
		int max = 0;
		
            
        /*@
          loop invariant c >= 1;
          loop invariant diff == \at(diff,Pre);
          loop invariant max == 0;
          loop invariant result >= 0;
          loop invariant result == sum_cubes(c - 1);
          loop invariant (c <= \at(diff,Pre)) ==> (result == sum_cubes(c - 1));
          loop invariant (c <= \at(diff,Pre)) ==> (result >= 0);
          loop invariant (!(c <= \at(diff,Pre))) ==> ((max == 0)&&(result >= 0)&&(diff == \at(diff,Pre)));
          loop assigns c, result;
            */
            for (int c = 1; c <= diff; c++) {
			result += c * c * c;
		}
            
		
            
        /*@
          loop invariant c >= 1;
          loop invariant diff == \at(diff,Pre);
          loop invariant result >= 0;
          loop invariant max >= 0;
          loop invariant max == ((c - 1) * c) / 2;
          loop invariant (c <= diff) ==> (max == ((c - 1) * c) / 2);
          loop assigns c, max;
            */
            for (int c = 1; c <= diff; c++) {
			max += c;
		}
            
		return result - max;
}
