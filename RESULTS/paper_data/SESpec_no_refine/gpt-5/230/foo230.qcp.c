#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo230(int * pairs, int pairs_len, int array);

int foo230(int * pairs, int pairs_len, int array) 
/*@
With pairs_l
Require store_int_array(pairs, pairs_len, pairs_l) && pairs_len > 0 && pairs_len < 100
Ensure Results(__return)
*/{

		int count = 0;
		int total = pairs_len;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for (int index = 0; index < total - 1; index++) {
		
 	/*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv emp */ /*1*/ 
 for (int k = index + 1; k < total; k++) {
				if (pairs[index] != pairs[k]) {
					count++;
				}
			}
		}
		return count;
}