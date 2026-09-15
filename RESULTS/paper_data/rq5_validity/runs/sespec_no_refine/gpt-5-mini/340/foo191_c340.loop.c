
/*@ 
  logic integer divisors_count(integer n, integer k) =
    k <= 0 ? 0 :
    divisors_count(n, k-1) + ((n % k == 0) ? 1 : 0);
*/

/*@
  requires \true;
*/
int foo191_c340(int n, int z) {

		if (z < 0) {
			z = -z;
		}
		int result = 0;
		
            
        /*@
          loop invariant 1 <= loop <= z + 1;
          loop invariant 0 <= result;
          loop invariant (loop <= \at(z,Pre)) ==> (result == divisors_count(n, loop-1) && z == \at(z,Pre) && n == \at(n,Pre));
          loop invariant n == \at(n,Pre);
          loop assigns loop, result;
        */
            for (int loop = 1; loop <= z; loop++) {
			if (n % loop == 0) {
				result = result + 1;
			}
		}
            
		return result;
}
