
/*@
  logic integer count_divisors(integer n, integer i) =
    i <= 0 ? 0 :
    (n % i == 0 ? 1 : 0) + count_divisors(n, i - 1);
*/

int foo192(int num, int z) {

		if (z < 0) {
			z = -z;
		}
		int result = 0;
		
            
        /*@
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
