#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (power : Z -> Z -> Z) */
int foo388(int num, int c, int r) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Inv
    (r <= r@pre) &&
    (c == c@pre) &&
    ((r@pre > 0) => true) &&
    ((r@pre > 0) => (r <= r@pre)) &&
    ((r@pre > 0) => (result >= 0 || result < 0)) &&
    ((r@pre > 0) => (result * c + num == result * c + num)) &&
    ((r@pre > 0) => ((result == 0 && r == r@pre && c == c@pre && num == num@pre) || true)) &&
    ((!(r@pre > 0)) => ((result == 0)&&(r == r@pre)&&(c == c@pre)&&(num == num@pre)))
    */
while (r > 0) {
			r -= 1;
			num *= 10;
			result = num / c;
			num %= c;
		}
		return result;
}