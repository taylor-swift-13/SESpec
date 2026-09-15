#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (mismatch_suffix : Z -> Z -> Z -> Z -> Z) */
/*@ Extern Coq (prefix_mismatch : Z -> Z -> Z -> Z) */
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
    (total == pairs_len@pre) &&
    (array == array@pre) &&
    (pairs_len == pairs_len@pre) &&
    (pairs == pairs@pre) &&
    (count >= 0) &&
    (forall (p:Z), 0 <= p && p < index => 0 <= pairs_l[p] && pairs_l[p] <= 100) &&
    (forall (p:Z), 0 <= p && p < index => forall (q:Z), p + 1 <= q && q < total => ((pairs_l[p] == pairs_l[q]) || (pairs_l[p] != pairs_l[q]))) &&
    (count == prefix_mismatch(pairs, total, index)) &&
    (true))
    */
for (int index = 0; index < total - 1; index++) {
			
            /*@
          loop invariant 0 <= index < total - 1;
          loop invariant index + 1 <= k <= total;
          loop invariant count >= 0;
          loop invariant count == prefix_mismatch(pairs, total, index) + mismatch_suffix(pairs, index, index + 1, k);
          loop invariant \forall integer t; index + 1 <= t < k ==> (pairs[index] == pairs[t] || pairs[index] != pairs[t]);
          loop invariant \valid_read(pairs + (0 .. total - 1));
          loop assigns count, k;
            */
            /*@ Inv
    exists  pairs_l,    
    store_int_array(pairs, pairs_len, pairs_l) &&
    (0 <= index && index < total - 1) &&
    (index + 1 <= k && k <= total) &&
    (count >= 0) &&
    (count == prefix_mismatch(pairs, total, index) + mismatch_suffix(pairs, index, index + 1, k)) &&
    (forall (t:Z), index + 1 <= t && t < k => (pairs_l[index] == pairs_l[t] || pairs_l[index] != pairs_l[t])) &&
    (true))
    */
for (int k = index + 1; k < total; k++) {
				if (pairs[index] != pairs[k]) {
					count++;
				}
			}
            
		}
		return count;
}