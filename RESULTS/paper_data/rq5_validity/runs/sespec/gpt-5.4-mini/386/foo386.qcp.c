#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo386(int num, int b, int r) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Inv
    (r <= r@pre) &&
    (b == b@pre) &&
    (r == r@pre => num == num@pre) &&
    (r == r@pre => result == 0) &&
    (r < r@pre || (num == num@pre && result == 0)) &&
    ((r@pre > 0) => (0 <= r && r <= r@pre)) &&
    ((r@pre > 0) => ((r == r@pre && result == 0) || r < r@pre)) &&
    ((!(r@pre > 0)) => ((result == 0)&&(r == r@pre)&&(b == b@pre)&&(num == num@pre)))
    */
while (r > 0) {
			r -= 1;
			num *= 10;
			result = num / b;
			num %= b;
		}
		return result;
}