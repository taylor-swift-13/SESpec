#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo245(int * pairs, int pairs_len, int num, int p) 
/*@
With pairs_l
Require store_int_array(pairs, pairs_len, pairs_l)
Ensure Results(__return)
*/{

		int ret = 0;
	
 	/*0*/ 
 /*@ Inv
    exists  pairs_l,    
    store_int_array(pairs, pairs_len, pairs_l) &&
    (0 <= index && index <= num) &&
    (ret >= 0)
    */
for (int index = 0; index < num; index++) {
		
 	/*1*/ 
 /*@ Inv
    exists  pairs_l,    
    store_int_array(pairs, pairs_len, pairs_l) &&
    (0 <= index && index < num) &&
    (index + 1 <= j && j <= num) &&
    (ret >= 0)
    */
for (int j = index + 1; j < num; j++) {
				if (pairs[index] + pairs[j] == p) {
					ret++;
				}
			}
		}
		return ret;
}