#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo228(int seed);

int foo228(int seed) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int *temp = (int *)malloc(sizeof(int) * (seed + 1));
int temp_len = seed + 1;
		temp[0] = 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 

		return temp[seed];
}