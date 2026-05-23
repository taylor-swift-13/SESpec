#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo198(int c);

int foo198(int c) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *arr = (int *)malloc(sizeof(int) * (c + 1));
int arr_len = c + 1;
		arr[0] = 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (loop assigns cat, arr_l[cat])
    */
    
            for (int cat = 1; cat <= c; cat++) {
			arr[cat] = 0;
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant \forall integer k; 0 <= k < n ==> arr[cat] >= arr[cat] - 0;
              loop assigns n, arr[cat];
            */
            for (int n = 0; n < cat; n++) {
				arr[cat] += arr[n]
						* arr[cat - n - 1];
			}
            
		}
		return arr[c];
}