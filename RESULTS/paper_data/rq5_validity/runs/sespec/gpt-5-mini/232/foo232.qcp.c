#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo232(int * pairs, int pairs_len, int array) 
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
    (total == pairs_len@pre) &&
    (0 <= count) &&
    (array == array@pre) &&
    (pairs_len == pairs_len@pre) &&
    (forall (i:Z), 0 <= i && i < pairs_len => 0 <= pairs_l[i] && pairs_l[i] <= 100) &&
    (forall (i:Z), 0 <= i && i < pairs_len => pairs_l[i] == pairs_l[i]@pre)
    */
for (int index = 0; index < total - 1; index++) {

        /*@
          loop invariant 0 <= index && index <= total - 1;
          loop invariant 0 <= count;
          loop invariant \forall integer k; 0 <= k < index ==>
                        (\forall integer j; k+1 <= j && j < total ==> pairs[k] != pairs[j] ==> \true);
          loop assigns index, c, count;
        */
        /*@ Inv
    exists  pairs_l,    
    store_int_array(pairs, pairs_len, pairs_l) &&
    (0 <= index && index <= total - 1) &&
    (0 <= count) &&
    (forall (k:Z), 0 <= k && k < index => (forall (j:Z), k+1 <= j && j < total => pairs_l[k] != pairs_l[j] => true))
    */
for (int c = index + 1; c < total; c++) {
            if (pairs[index] != pairs[c]) {
                count++;
            }
        }

    }
		return count;
}