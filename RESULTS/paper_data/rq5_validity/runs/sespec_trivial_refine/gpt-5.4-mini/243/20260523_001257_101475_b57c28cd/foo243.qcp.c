#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (prefix_pairs : Z -> Z -> Z -> Z -> Z) */
/*@ Extern Coq (suffix_pairs : Z -> Z -> Z -> Z -> Z) */

int foo243(int * pairs, int pairs_len, int num, int p) 
/*@
With pairs_l
Require store_int_array(pairs, pairs_len, pairs_l)
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*0*/ 
 /*@ Inv
    exists  pairs_l,    
    store_int_array(pairs, pairs_len, pairs_l) &&
    (0 <= index && index <= num) &&
    (result == prefix_pairs(pairs, num, index, p))
    */
for (int index = 0; index < num; index++) {
		
 	/*1*/ 
 /*@ Inv
    exists  pairs_l,    
    store_int_array(pairs, pairs_len, pairs_l) &&
    (0 <= index && index < num) &&
    (index + 1 <= j && j <= num) &&
    (result == prefix_pairs(pairs, num, index, p) + suffix_pairs(pairs, index, j, p))
    */
for (int j = index + 1; j < num; j++) {
				if (pairs[index] + pairs[j] == p) {
					result++;
				}
			}
		}
		return result;
}