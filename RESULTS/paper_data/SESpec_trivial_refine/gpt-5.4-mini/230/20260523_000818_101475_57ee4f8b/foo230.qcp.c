#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo230(int * pairs, int pairs_len, int array) 
/*@
With pairs_l
Require store_int_array(pairs, pairs_len, pairs_l)
Ensure Results(__return)
*/{

		int count = 0;
		int total = pairs_len;
	
 	/*0*/ 
 /*@ Inv
    exists  pairs_l,    
    store_int_array(pairs, pairs_len, pairs_l) &&
    (0 <= index && index <= total) &&
    (0 <= count)
    */
for (int index = 0; index < total - 1; index++) {
		
 	/*1*/ 
 /*@ Inv
    exists  pairs_l,    
    store_int_array(pairs, pairs_len, pairs_l) &&
    (0 <= index && index <= total - 1) &&
    (index + 1 <= k && k <= total) &&
    (0 <= count)
    */
for (int k = index + 1; k < total; k++) {
				if (pairs[index] != pairs[k]) {
					count++;
				}
			}
		}
		return count;
}