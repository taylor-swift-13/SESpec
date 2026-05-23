#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo57_c199(int number);

int foo57_c199(int number) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *arr = (int *)malloc(sizeof(int) * (number + 1));
int arr_len = number + 1;
		arr[0] = 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (1 <= c && c <= number + 1) &&
(arr_len == number + 1) &&
(arr_l[0] == 1) &&
(forall (i:Z), 0 <= i && i < c => arr_l[i] >= 0
          loop assigns c, arr_l[1 .. number])
    */
    
            for (int c = 1; c <= number; c++) {
        arr[c] = 0;
        
        /* >>> LOOP INVARIANT TO FILL <<< */
        
        /*@
          loop invariant 0 <= n <= c;
          loop invariant 1 <= c <= number;
          loop invariant \forall integer i; 0 <= i < c ==> arr[i] >= 0;
          loop invariant arr[c] == conv_sum(arr, c, n);
          loop assigns arr[c];
        */
        for (int n = 0; n < c; n++) {
            arr[c] += arr[n]
                    * arr[c - n - 1];
        }
        
    }
		return arr[number];
}