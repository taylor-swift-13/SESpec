
/*@
  logic integer divcount(integer num, integer n) =
    n <= 0 ? 0 : divcount(num, n - 1) + ((num % n) == 0 ? 1 : 0);
*/

int foo341(int num, int z) {

		if (z < 0) {
			z = -z;
		}
		int result = 0;
		
        /*@
          loop invariant 1 <= loop <= z + 1;
          loop invariant 0 <= result <= loop - 1;
          loop invariant result == divcount(num, loop - 1);
          loop invariant (\forall integer k; 1 <= k < loop ==> (num % k == 0) ==> result >= 0);
          loop invariant z == (\at(z,Pre) >= 0 ? \at(z,Pre) : -\at(z,Pre));
          loop invariant num == \at(num,Pre);
          loop invariant (loop <= z + 1) ==> (0 <= result <= z);
          loop invariant (loop > z) ==> (result == divcount(num, z));
          loop assigns loop, result;
        */
        for (int loop = 1; loop <= z; loop++) {
			if (num % loop == 0) {
				result = result + 1;
			}
		}
            
		return result;
}
