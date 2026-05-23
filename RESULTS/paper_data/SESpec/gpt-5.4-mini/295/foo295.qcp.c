#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (fib295 : Z -> Z) */
int foo295(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *result = (int *)malloc(sizeof(int) * (num + 1));
int result_len = num + 1;
		result[0] = 2;
		result[1] = 1;
	
 	/*@ Inv
    (2 <= l && l <= num + 1) &&
    (result[0] == fib295(0)) &&
    (result[1] == fib295(1)) &&
    (l >= 2 => result[l - 1] == fib295(l - 1)) &&
    (l >= 3 => result[l - 2] == fib295(l - 2))
    */
for (int l = 2; l <= num; l++) {
        result[l] = result[l - 1] + result[l - 2];
    }
		return result[num];
}