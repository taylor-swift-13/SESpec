#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
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
    (1 <= l) &&
    (1 <= ret && ret <= l) &&
    (n <= y) &&
    (n % ret == 0 && y % ret == 0) &&
    (forall (k:Z), 1 <= k && k < l && n % k == 0 && y % k == 0 => k <= ret) &&
    (exists (k:Z), 1 <= k && k <= ret && n % k == 0 && y % k == 0)
    */
for (int l = 1; l <= n; l++) {
			if (n % l == 0 && y % l == 0) {
				ret = l;
			}
		}
		g = (n * y) / ret;
		return g;
}