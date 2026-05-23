#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo55_c197(int n);

int foo55_c197(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *arr = (int *)malloc(sizeof(int) * (n + 1));
int arr_len = n + 1;
		arr[0] = 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for (int c = 1; c <= n; c++) {
			arr[c] = 0;
		
 	/*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv emp */ /*1*/ 
 for (int k = 0; k < c; k++) {
				arr[c] += arr[k]
						* arr[c - k - 1];
			}
		}
		return arr[n];
}