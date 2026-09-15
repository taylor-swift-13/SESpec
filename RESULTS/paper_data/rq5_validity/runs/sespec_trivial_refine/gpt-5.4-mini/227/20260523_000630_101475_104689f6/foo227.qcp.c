#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (sum_prefix : Z -> Z -> Z) */
int foo227(int b) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int *arr = (int *)malloc(sizeof(int) * (b + 1));
int arr_len = b + 1;
		arr[0] = 1;
	
 	/*@ Inv
    (1 <= d && d <= b + 1) &&
    (arr[0] == 1)
    */
for (int d = 1; d <= b; d++) {
			
            /*@
              loop invariant 0 <= c <= d;
              loop invariant arr[0] == 1;
              loop assigns c, arr[d];
            */
            /*@ Inv
    (0 <= c && c <= d) &&
    (arr[0] == 1)
    */
for (int c = 0; c < d; c++) {
				arr[d] = arr[d] + arr[c];
			}
            
		}
		return arr[b];
}