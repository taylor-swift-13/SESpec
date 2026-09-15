#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (valid_pairs : Z -> Z -> Prop) */

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
    (valid_pairs(pairs, pairs_len)) &&
    (0 <= ret && ret <= (num*(num-1))/2) &&
    (forall (i:Z), 0 <= i && i < index => (forall (j:Z), i < j && j < num => true)) &&
    (forall (k:Z), 0 <= k && k < pairs_len => 0 <= pairs_l[k] && pairs_l[k] <= 100)
    */
for (int index = 0; index < num; index++) {
		
 	/*1*/ 
 /*@ Inv
    exists  pairs_l,    
    store_int_array(pairs, pairs_len, pairs_l) &&
    (index + 1 <= j && j <= num) &&
    (0 <= index && index < num) &&
    (valid_pairs(pairs, pairs_len)) &&
    (0 <= ret) &&
    (forall (i:Z), 0 <= i && i < index => (forall (j:Z), i < j && j < num => true))
    */
for (int j = index + 1; j < num; j++) {
				if (pairs[index] + pairs[j] == p) {
					ret++;
				}
			}
		}
		return ret;
}