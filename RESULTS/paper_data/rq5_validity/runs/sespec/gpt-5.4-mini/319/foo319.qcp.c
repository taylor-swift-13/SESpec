#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo319(int n, int y) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 1;
		int l = 1;
		if (n > y) {
			int g = n;
			n = y;
			y = g;
		}
	
 	/*@ Inv
    (1 <= j) &&
    (ret >= 1) &&
    (ret <= j) &&
    (n % ret == 0) &&
    (y % ret == 0) &&
    (forall (k:Z), 1 <= k && k < j && n % k == 0 && y % k == 0 => k <= ret) &&
    (n == y@pre) &&
    (y == n@pre) &&
    (l == 1)
    */
for (int j = 1; j <= n; j++) {
			if (n % j == 0 && y % j == 0) {
				ret = j;
			}
		}
		l = (n * y) / ret;
		return l;
}