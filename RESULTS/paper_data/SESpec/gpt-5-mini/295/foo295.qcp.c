#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (fib : Z -> Z) */
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
    (2 <= l) &&
    (l <= num + 1) &&
    (result_len == num + 1 && 0 <= num) &&
    ((l <= num) => (result[l-1] == fib(l-1) && result[l-2] == fib(l-2))) &&
    ((!(l <= num)) => (result[num] == fib(num)))
    */
for (int l = 2; l <= num; l++) {
			result[l] = result[l - 1]
					+ result[l - 2];
		}
		return result[num];
}