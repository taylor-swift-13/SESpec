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
    ((r@pre > 0) => (r >= 0)) &&
    ((r@pre > 0) => (r <= r@pre)) &&
    ((r@pre > 0) => (r@pre - r >= 0)) &&
    ((r@pre > 0) => (r@pre - r <= r@pre)) &&
    ((r@pre > 0) => (r == 0 => (r@pre - r == r@pre))) &&
    ((r@pre > 0) => (0 <= r && r <= r@pre)) &&
    ((r@pre > 0) => (r >= 0)) &&
    ((r@pre > 0) => (r <= r@pre)) &&
    ((r@pre > 0) => (c == c@pre)) &&
    ((r@pre > 0) => (((result == 0)&&(r == r@pre)&&(c == c@pre)&&(num == num@pre)) || ((r < r@pre)))) &&
    ((!(r@pre > 0)) => ((result == 0)&&(r == r@pre)&&(c == c@pre)&&(num == num@pre))) &&
    (c == c@pre)
    */
while (r > 0) {
			r -= 1;
			num *= 10;
			result = num / c;
			num %= c;
		}
		return result;
}