#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_pairs : Z -> Z -> Z -> Z) */
int foo230(int * pairs, int pairs_len, int array) 
/*@
With pairs_l
Require store_int_array(pairs, pairs_len, pairs_l)
Ensure Results(__return)
*/{

		int count = 0;
		int total = pairs_len;
	
 	/*@ Inv
    exists  pairs_l,    
    store_int_array(pairs, pairs_len, pairs_l) &&
    (0 <= index && index <= total) &&
    (count >= 0) &&
    (total == pairs_len@pre) &&
    (array == array@pre) &&
    (pairs_len == pairs_len@pre) &&
    (pairs == pairs@pre)
    */
for (int index = 0; index < total - 1; index++) {

        /*@
          loop invariant index + 1 <= k <= total;
          loop invariant count >= 0;
          loop invariant \forall integer i, j; 0 <= i <= index && i < j < k ==> pairs[i] != pairs[j] || count >= 0;
          loop assigns k, count;
        */
        /*@ Inv
    exists  pairs_l,    
    store_int_array(pairs, pairs_len, pairs_l) &&
    (index + 1 <= k && k <= total) &&
    (count >= 0) &&
    (forall (i:Z), forall (j:Z), 0 <= i && i <= index && i < j && j < k => pairs_l[i] != pairs_l[j] || count >= 0)
    */
for (int k = index + 1; k < total; k++) {
            if (pairs[index] != pairs[k]) {
                count++;
            }
        }
    }
		return count;
}