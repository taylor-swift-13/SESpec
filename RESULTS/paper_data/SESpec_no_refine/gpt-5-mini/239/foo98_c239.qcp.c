#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo98_c239(int * ar, int ar_len, int n);

int foo98_c239(int * ar, int ar_len, int n) 
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
/*@ Inv emp */ /*0*/ 
 for (int i = 1; i <= n; i++) {
            if (ar[i - 1] == i) {
                missing = i;
            } else if (ar[i - 1] != i) {
                return i;
            }
        }
        return missing;
}