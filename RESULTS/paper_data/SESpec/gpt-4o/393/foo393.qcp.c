#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (factorial : Z -> Z) */
int foo393(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 1;
	
 	/*@ Inv
    (1 <= loop && loop <= num + 1) &&
    (ret == factorial(loop - 1)) &&
    (num >= 0) &&
    (num == num@pre) &&
    ((loop <= num) => (ret == factorial(loop - 1))) &&
    ((!(loop <= num)) => ((ret == factorial(num)) && (num == num@pre)))
    */
for (int loop = 1; loop <= num; loop++) {
        ret *= loop;
    }
		int remainder = (int) (ret % 100);
		return remainder;
}