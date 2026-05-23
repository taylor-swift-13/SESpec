#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (valid_array : Z -> Z -> Prop) */
/*@ Extern Coq (sum : Z -> Z -> Z -> Z) */

int foo227(int b) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int *arr = (int *)malloc(sizeof(int) * (b + 1));
int arr_len = b + 1;
		arr[0] = 1;
	
 	/*0*/ 
 /*@ Inv
    (arr[0] == 1)
    */
for (int d = 1; d <= b; d++) {
		
 	/*1*/ 
 for (int c = 0; c < d; c++) {
				arr[d] = arr[d] + arr[c];
			}
		}
		return arr[b];
}