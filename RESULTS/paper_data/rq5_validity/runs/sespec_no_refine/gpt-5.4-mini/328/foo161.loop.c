
/*@
  logic integer sum_cubes(integer n) =
    n <= 0 ? 0 : sum_cubes(n - 1) + n * n * n;
*/

/*@ 
  logic integer sum_nat(integer n) =
    n <= 0 ? 0 : sum_nat(n - 1) + n;
*/


int foo161(int diff) {

		int result = 0;
		int max = 0;
		
        /*@
          loop invariant 0 <= c;
          loop invariant (c <= diff) ==> (result == sum_cubes(c - 1));
          loop invariant (!(c <= diff)) ==> (result == sum_cubes(diff));
          loop invariant max == 0;
          loop invariant diff == \at(diff,Pre);
          loop assigns c, result;
        */
            for (int c = 1; c <= diff; c++) {
			result += c * c * c;
		}
            
        /*@
          loop invariant 0 <= c;
          loop invariant (c <= diff) ==> (max == sum_nat(c - 1));
          loop invariant (!(c <= diff)) ==> (max == sum_nat(diff));
          loop invariant result == sum_cubes(diff);
          loop invariant diff == \at(diff,Pre);
          loop assigns c, max;
        */
		
		
        
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (!(c <= diff)) ==> ();
          loop assigns c, max;
            */
            for (int c = 1; c <= diff; c++) {
			max += c;
		}
            
		return result - max;
}
