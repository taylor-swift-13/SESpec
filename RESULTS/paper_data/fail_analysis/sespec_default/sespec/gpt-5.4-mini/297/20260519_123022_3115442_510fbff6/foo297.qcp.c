#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo297(int seed);

int foo297(int seed) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *result = (int *)malloc(sizeof(int) * (seed + 1));
int result_len = seed + 1;
		result[0] = 2;
		result[1] = 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((l <= seed) => (l >= 2 && result_l[l - 1] == fib(l - 1) && result_l[l - 2] == fib(l - 2))
          loop assigns l, result_l[0..seed])
    */
    
            for (int l = 2; l <= seed; l++) {
			result[l] = result[l - 1]
					+ result[l - 2];
		}
		return result[seed];
}