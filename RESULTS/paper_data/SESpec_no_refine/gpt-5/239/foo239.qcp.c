#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo239(int * ar, int ar_len, int n);

int foo239(int * ar, int ar_len, int n) 
/*@
With ar_l
Require store_int_array(ar, ar_len, ar_l) && ar_len > 0 && ar_len < 100
Ensure Results(__return)
*/{

        int missing = 1;
        if (n == 0 || n == 1) {
            return missing;
        }
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  ar_l,    
    store_int_array(ar, ar_len, ar_l) && ar_len > 0 && ar_len < 100 &&
    (1 <= missing && missing <= i) &&
(prefix_match(ar, i)) &&
(missing == (prefix_match(ar, i) ? (i-1 >= 1 ? i-1 : 1) : missing)) &&
(forall (k:Z), 0 <= k && k < (i-1) => ar_l[k] == (k+1)) &&
(forall (k:Z), 0 <= k && k < ar_len => ar_l[k] == ar_l[k]@pre
          loop assigns i, missing)
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