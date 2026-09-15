#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo295(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *result = (int *)malloc(sizeof(int) * (num + 1));
int result_len = num + 1;
		result[0] = 2;
		result[1] = 1;
	
 	/*0*/ 
 /*@ Inv
    (2 <= l && l <= num + 1) &&
    (result[0] == 2) &&
    (result[1] == 1) &&
    (forall (i:Z), 2 <= i && i < l => result[i] == result[i - 1] + result[i - 2])
    */
for (int l = 2; l <= num; l++) {
			result[l] = result[l - 1]
					+ result[l - 2];
		}
		return result[num];
}