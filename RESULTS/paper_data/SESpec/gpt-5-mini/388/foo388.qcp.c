#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo388(int num, int c, int r) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Inv
    (r <= r@pre) &&
    ((r@pre - r) >= 0) &&
    ((r@pre - r == 0) => (result == 0 && num == num@pre)) &&
    (c == c@pre) &&
    (r >= 0 || r <= r@pre)
    */
while (r > 0) {
        r -= 1;
        num *= 10;
        result = num / c;
        num %= c;
    }
		return result;
}