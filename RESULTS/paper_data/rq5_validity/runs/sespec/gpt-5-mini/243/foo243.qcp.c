#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo243(int * pairs, int pairs_len, int num, int p) 
/*@
With pairs_l
Require store_int_array(pairs, pairs_len, pairs_l)
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Inv
    exists  pairs_l,    
    store_int_array(pairs, pairs_len, pairs_l) &&
    (0 <= index) &&
    (0 <= result) &&
    (p == p@pre) &&
    (num == num@pre) &&
    (pairs_len == pairs_len@pre) &&
    (pairs == pairs@pre) &&
    (forall (k:Z), 0 <= k && k < pairs_len => 0 <= pairs_l[k] && pairs_l[k] <= 100)
    */
for (int index = 0; index < num; index++) {

        /*@
          loop invariant index + 1 <= j && j <= num;
          loop invariant 0 <= result;
          loop invariant p == \at(p,Pre);
          loop invariant num == \at(num,Pre);
          loop invariant pairs_len == \at(pairs_len,Pre);
          loop invariant pairs == \at(pairs,Pre);
          loop invariant \forall integer k; 0 <= k < pairs_len ==> 0 <= pairs[k] <= 100;
          loop assigns j, result;
        */
        /*@ Inv
    exists  pairs_l,    
    store_int_array(pairs, pairs_len, pairs_l) &&
    (index + 1 <= j && j <= num) &&
    (0 <= result) &&
    (p == p@pre) &&
    (num == num@pre) &&
    (pairs_len == pairs_len@pre) &&
    (pairs == pairs@pre) &&
    (forall (k:Z), 0 <= k && k < pairs_len => 0 <= pairs_l[k] && pairs_l[k] <= 100)
    */
for (int j = index + 1; j < num; j++) {
            if (pairs[index] + pairs[j] == p) {
                result++;
            }
        }

    }
		return result;
}