#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_matching_prefix : Z -> Z -> Z) */
int foo239(int * ar, int ar_len, int n) 
/*@
With ar_l
Require store_int_array(ar, ar_len, ar_l)
Ensure Results(__return)
*/{

        int missing = 1;
        if (n == 0 || n == 1) {
            return missing;
        }
       
  /*@ Inv
    exists  ar_l,    
    store_int_array(ar, ar_len, ar_l) &&
    (1 <= i) &&
    (1 <= missing && missing <= i) &&
    ((i == 1 => missing == 1)) &&
    ((i > 1 => missing == i - 1)) &&
    (forall (k:Z), 1 <= k && k < i => ar_l[k - 1] == k) &&
    (forall (k:Z), 1 <= k && k < i => missing >= k) &&
    ((i > n) => forall (k:Z), 1 <= k && k <= n => ar_l[k - 1] == k)
    */
for (int i = 1; i <= n; i++) {
            if (ar[i - 1] == i) {
                missing = i;
            } else if (ar[i - 1] != i) {
                return i;
            }
        }
        return missing;
}