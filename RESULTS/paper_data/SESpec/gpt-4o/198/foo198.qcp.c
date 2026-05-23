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
    (forall (i:Z), 0 <= i && i < cat => arr_l[i] >= 0) &&
(forall (i:Z), 0 <= i && i < cat => (i == 0 ? arr_l[i] == 1 : arr_l[i] == sum_of_products(arr, i, i))
      loop assigns arr_l[0..c])
    */
    
    for (int cat = 1; cat <= c; cat++) {
        arr[cat] = 0;

        /*@
          loop invariant 0 <= n <= cat;
          loop invariant arr[cat] == sum_of_products(arr, n, cat);
          loop invariant \forall integer i; 0 <= i < cat ==> arr[i] >= 0;
          loop assigns arr[cat];
        */
        for (int n = 0; n < cat; n++) {
            arr[cat] += arr[n] * arr[cat - n - 1];
        }
    }
		return arr[c];
}