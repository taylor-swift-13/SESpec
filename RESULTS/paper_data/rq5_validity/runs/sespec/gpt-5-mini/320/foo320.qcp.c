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
	
 	/*0*/ 
 /*@ Inv
    (1 <= l && l <= n + 1) &&
    (1 <= ret && ret <= y@pre) &&
    (0 <= n && 0 <= y) &&
    (forall (d:Z), 1 <= d && d < l => ((n % d == 0 && y % d == 0) => (ret % d == 0))) &&
    (forall (d:Z), 1 <= d && d < l => ((n % d == 0 && y % d == 0) => d <= ret)) &&
    ((exists (d:Z), 1 <= d && d < l && n % d == 0 && y % d == 0 && d == ret) || ret == 1) &&
    ((l <= y@pre) => (ret > 0)) &&
    ((l <= y@pre) => (((g == 1) && (ret == 1) && (y == n@pre) && (n == y@pre)) || (ret > 0))) &&
    ((!(l <= y@pre)) => ((g == 1) && (ret == 1) && (y == n@pre) && (n == y@pre))) &&
    (g == 1) &&
    (y == n@pre) &&
    (n == y@pre)
    */
for (int l = 1; l <= n; l++) {
			if (n % l == 0 && y % l == 0) {
				ret = l;
			}
		}
		g = (n * y) / ret;
		return g;
}