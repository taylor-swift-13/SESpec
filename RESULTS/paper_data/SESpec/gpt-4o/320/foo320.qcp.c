#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (gcd_property : Z -> Z -> Z -> Z -> Prop) */
int foo320(int n, int y) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 1;
		int g = 1;
		if (n > y) {
			int r = n;
			n = y;
			y = r;
		}
	
 	/*@ Inv
    (ret >= 1) &&
    (forall (k:Z), 1 <= k && k < l => gcd_property(n, y, k, ret)) &&
    (exists (k:Z), 1 <= k && k <= l && n % k == 0 && y % k == 0 && ret == k) &&
    ((l <= y@pre) => ((ret >= 1) && (ret <= l))) &&
    (g == 1) &&
    (y == n@pre || y == y@pre) &&
    (n == y@pre || n == n@pre)
    */
for (int l = 1; l <= n; l++) {
        if (n % l == 0 && y % l == 0) {
            ret = l;
        }
    }
		g = (n * y) / ret;
		return g;
}