#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (dummy : Z -> Z) */
int foo229(int seed) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int *arr = (int *)malloc(sizeof(int) * (seed + 1));
int arr_len = seed + 1;
		arr[0] = 1;
	
 	/*@ Inv
    (1 <= d && d <= seed + 1) &&
    (arr[0] == 1)
    */
for (int d = 1; d <= seed; d++) {
			
            /* >>> LOOP INVARIANT TO FILL <<< */
            /*@
              loop invariant 1 <= d <= seed;
              loop invariant 0 <= c <= d;
              loop assigns c, arr[d];
            */
            /*@ Inv
    (1 <= d && d <= seed) &&
    (0 <= c && c <= d)
    */
for (int c = 0; c < d; c++) {
				arr[d] = arr[d] + arr[c];
			}
            
		}
		return arr[seed];
}