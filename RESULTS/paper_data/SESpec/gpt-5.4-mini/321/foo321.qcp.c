#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
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
    (1 <= l) &&
    (ret >= 1) &&
    (ret <= l) &&
    (n % ret == 0 && y % ret == 0) &&
    (forall (k:Z), 1 <= k && k < l && n % k == 0 && y % k == 0 => k <= ret) &&
    (exists (k:Z), 1 <= k && k <= ret && n % k == 0 && y % k == 0) &&
    (n <= y) &&
    (n == n@pre || n == y@pre) &&
    (y == n@pre || y == y@pre)
    */
for (int l = 1; l <= n; l++) {
			if (n % l == 0 && y % l == 0) {
				ret = l;
			}
		}
		r = (n * y) / ret;
		return r;
}