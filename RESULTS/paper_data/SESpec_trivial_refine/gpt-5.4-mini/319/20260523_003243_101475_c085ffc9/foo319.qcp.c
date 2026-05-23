#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (divides : Z -> Z -> Prop) */
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
    (1 <= ret && ret <= j) &&
    (divides(ret, n) && divides(ret, y)) &&
    (forall (k:Z), 1 <= k && k < j => (divides(k, n) && divides(k, y) => k <= ret))
    */
for (int j = 1; j <= n; j++) {
			if (n % j == 0 && y % j == 0) {
				ret = j;
			}
		}
		l = (n * y) / ret;
		return l;
}