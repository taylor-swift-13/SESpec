#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo293(int seed);

int foo293(int seed) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *arr = (int *)malloc(sizeof(int) * (seed + 1));
int arr_len = seed + 1;
		arr[0] = 0;
		arr[1] = 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (2 <= p) &&
(arr_l[0] == 0) &&
(arr_l[1] == 1) &&
(forall (i:Z), 0 <= i && i < p => arr_l[i] == (i <= 1 ? i : (2 * arr_l[i - 1] + arr_l[i - 2]) % 1000000000)
          loop assigns p, arr_l[0..seed])
    */
    
            for (int p = 2; p <= seed; p++) {
			arr[p] = (2 * arr[p - 1]
					+ arr[p - 2]) % 1000000000;
		}
		return arr[seed];
}