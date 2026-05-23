
/*@ logic integer sum_cubes(integer n) =
      n <= 0 ? 0 : sum_cubes(n - 1) + n * n * n; */
/*@ 
  assigns \nothing;
*/
int foo328(int diff) {

		int result = 0;
		int max = 0;
		
        /*@
          loop invariant 1 <= c;
          loop invariant result == sum_cubes(c - 1);
          loop invariant max == 0;
          loop invariant diff == \at(diff,Pre);
          loop assigns c, result;
        */
        for (int c = 1; c <= diff; c++) {
			result += c * c * c;
		}
            
        /*@
          loop invariant 0 <= c;
          loop invariant max == (c - 1) * c / 2;
          loop invariant diff == \at(diff,Pre);
          loop assigns c, max;
        */
        for (int c = 1; c <= diff; c++) {
			max += c;
		}
            
		return result - max;
}
