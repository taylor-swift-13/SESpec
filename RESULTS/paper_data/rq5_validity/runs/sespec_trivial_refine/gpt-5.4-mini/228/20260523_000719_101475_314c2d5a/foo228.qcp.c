#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (prefix_sum : Z -> Z -> Z -> Z) */

int foo228(int seed) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int *temp = (int *)malloc(sizeof(int) * (seed + 1));
int temp_len = seed + 1;
		temp[0] = 1;
	
 	/*0*/ 
 /*@ Inv
    (1 <= d && d <= seed + 1) &&
    (temp[0] == 1)
    */
for (int d = 1; d <= seed; d++) {
		
 	/*1*/ 
 /*@ Inv
    (0 <= c && c <= d) &&
    (d <= seed)
    */
for (int c = 0; c < d; c++) {
				temp[d] = temp[d] + temp[c];
			}
		}
		return temp[seed];
}