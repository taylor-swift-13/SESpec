#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (power : Z -> Z -> Z) */
int foo387(int num, int c, int r) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 0;
	
 	/*@ Inv
    (r >= 0) &&
    (num >= 0) &&
    (c == c@pre) &&
    (ret >= 0) &&
    ((r@pre > 0) => (r <= r@pre)) &&
    ((!(r@pre > 0)) => ((ret == 0) && (r == r@pre) && (c == c@pre) && (num == num@pre)))
    */
while (r > 0) {
        r -= 1;
        num *= 10;
        ret = num / c;
        num %= c;
    }
		return ret;
}