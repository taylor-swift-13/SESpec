#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (gcd : Z -> Z -> Z) */
int foo321(int n, int y) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 1;
		int r = 1;
		if (n > y) {
			int g = n;
			n = y;
			y = g;
		}
	
 	/*@ Inv
    (1 <= l && l <= n + 1) &&
    (ret >= 1) &&
    (ret <= l) &&
    (ret <= n) &&
    (ret <= y) &&
    ((n % ret == 0) && (y % ret == 0)) &&
    (forall (k:Z), 1 <= k && k < l => ((n % k == 0) && (y % k == 0)) => k <= ret)
    */
for (int l = 1; l <= n; l++) {
        if (n % l == 0 && y % l == 0) {
            ret = l;
        }
    }
		r = (n * y) / ret;
		return r;
}