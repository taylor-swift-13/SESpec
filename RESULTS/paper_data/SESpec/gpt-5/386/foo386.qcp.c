#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (pow10 : Z -> Z) */
int foo386(int num, int b, int r) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Inv
    (b == b@pre) &&
    (r@pre - r >= 0) &&
    ((r@pre > 0) => (b == b@pre)) &&
    ((r@pre > 0) => (0 <= r && r <= r@pre)) &&
    ((!(r@pre > 0)) => ((result == 0)&&(r == r@pre)&&(b == b@pre)&&(num == num@pre))) &&
    (b == b@pre)
    */
while (r > 0) {
        r -= 1;
        num *= 10;
        result = num / b;
        num %= b;
    }
		return result;
}