
#include <limits.h>

int foo191(int n, int z) {
		if (z < 0) {
			z = -z;
		}
		int result = 0;
		
            /*@
          loop invariant (loop <= \at(z,Pre)) ==> (result >= 0);
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
