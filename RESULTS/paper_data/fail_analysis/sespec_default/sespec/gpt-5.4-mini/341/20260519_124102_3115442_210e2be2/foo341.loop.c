
/*@
logic integer count_divisors(integer n, integer k) =
  k <= 0 ? 0 :
  (k > n ? 0 :
   ((n % k == 0) ? 1 : 0) + count_divisors(n, k + 1));
*/

int foo341(int num, int z) {

		if (z < 0) {
			z = -z;
		}
		int result = 0;
		
            
        /*@
          loop invariant 1 <= loop <= z + 1;
          loop invariant 0 <= result <= loop - 1;
          loop invariant z == (\at(z,Pre) < 0 ? -\at(z,Pre) : \at(z,Pre));
          loop invariant num == \at(num,Pre);
          loop assigns loop, result;
        */
            for (int loop = 1; loop <= z; loop++) {
			if (num % loop == 0) {
				result = result + 1;
			}
		}
            
		return result;
}
