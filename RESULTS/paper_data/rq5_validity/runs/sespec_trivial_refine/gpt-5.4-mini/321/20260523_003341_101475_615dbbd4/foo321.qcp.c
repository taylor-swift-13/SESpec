#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (divides : Z -> Z -> Prop) */
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
    (n >= 0 => l <= n + 1) &&
    (1 <= ret && ret <= l) &&
    (divides(ret, n) && divides(ret, y)) &&
    (forall (k:Z), 1 <= k && k < l && divides(k, n) && divides(k, y) => k <= ret)
    */
for (int l = 1; l <= n; l++) {
			if (n % l == 0 && y % l == 0) {
				ret = l;
			}
		}
		r = (n * y) / ret;
		return r;
}