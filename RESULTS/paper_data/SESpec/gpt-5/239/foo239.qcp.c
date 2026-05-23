#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
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
    (forall (k:Z), 0 <= k && k < ar_len => ar_l[k] == ar_l[k]@pre) &&
    (forall (j:Z), 1 <= j && j < i => ar_l[j - 1] == j) &&
    ((i > 1) => (missing == i - 1)) &&
    (forall (j:Z), (j < 1 || j >= i) => true) &&
    ((i <= n) => (ar_l[i - 1] == i || true))
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