#include <limits.h>

int findDivisor(int num, int z);

 /*@
    requires z != INT_MIN;
    assigns \nothing;
    ensures 0 <= \result;
    ensures \result <= (\old(z) < 0 ? -\old(z) : \old(z));
    ensures \result == \sum integer i; 1 <= i <= (\old(z) < 0 ? -\old(z) : \old(z)); (num % i) == 0;
 */
int findDivisor(int num, int z) {

		if (z < 0) {
			z = -z;
		}
		int result = 0;
		/*@
		    loop invariant 1 <= loop <= z + 1;
		    loop invariant 0 <= result <= z;
		    loop invariant result == \sum integer i; 1 <= i <= loop-1; (num % i) == 0;
		    loop assigns loop, result;
		    loop variant z - loop + 1;
		*/
		for (int loop = 1; loop <= z; loop++) {
			if (num % loop == 0) {
				result = result + 1;
			}
		}
		return result;
}
