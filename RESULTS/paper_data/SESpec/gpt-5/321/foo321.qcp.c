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
    (ret <= l) &&
    (1 <= ret) &&
    (forall (k:Z), 1 <= k && k < l => ((n % k == 0 && y % k == 0) => ret >= k)) &&
    ((n % ret == 0) && (y % ret == 0)) &&
    (forall (d:Z), 1 <= d && d < l => ((n % d == 0 && y % d == 0) => d <= ret)) &&
    ((l == 1) => (ret == 1)) &&
    ((l <= y@pre) => (ret <= y@pre)) &&
    ((l <= y@pre) => ((n % ret == 0) && (y % ret == 0))) &&
    ((l <= y@pre) => (((r == 1)&&(ret == 1)&&(y == n@pre)&&(n == y@pre)) || (ret <= l && ret >= 1 && n % ret == 0 && y % ret == 0))) &&
    (r == 1)
    */
for (int l = 1; l <= n; l++) {
			if (n % l == 0 && y % l == 0) {
				ret = l;
			}
		}
		r = (n * y) / ret;
		return r;
}