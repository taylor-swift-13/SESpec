#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_pairs_with : Z -> Z -> Z -> Z) */
/*@ Extern Coq (count_pairs_sum : Z -> Z -> Z -> Z) */
int foo245(int * pairs, int pairs_len, int num, int p) 
/*@
With pairs_l
Require store_int_array(pairs, pairs_len, pairs_l)
Ensure Results(__return)
*/{

		int ret = 0;
	
 	/*@ Inv
    exists  pairs_l,    
    store_int_array(pairs, pairs_len, pairs_l) &&
    (0 <= index) &&
    (forall (k:Z), 0 <= k && k < pairs_len => 0 <= pairs_l[k] && pairs_l[k] <= 100) &&
    (forall (k:Z), 0 <= k && k < pairs_len => pairs_l[k] == pairs_l[k]@pre) &&
    ((index < num@pre) => (ret >= 0)) &&
    ((index < num@pre) => (0 <= index)) &&
    ((index < num@pre) => (index <= num@pre)) &&
    (p == p@pre) &&
    (num == num@pre) &&
    (pairs_len == pairs_len@pre) &&
    (pairs == pairs@pre)
    */
for (int index = 0; index < num; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant index + 1 <= j <= num;
          loop invariant 0 <= ret;
          loop assigns j, ret;
            */
            /*@ Inv
    exists  pairs_l,    
    store_int_array(pairs, pairs_len, pairs_l) &&
    (index + 1 <= j && j <= num) &&
    (0 <= ret)
    */
for (int j = index + 1; j < num; j++) {
				if (pairs[index] + pairs[j] == p) {
					ret++;
				}
			}
            
		}
		return ret;
}