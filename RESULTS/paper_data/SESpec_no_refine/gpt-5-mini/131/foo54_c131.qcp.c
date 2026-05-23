#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo54_c131(int * a, int a_len);

int foo54_c131(int * a, int a_len) 
/*@
With a_l
Require store_int_array(a, a_len, a_l) && a_len > 0 && a_len < 100
Ensure Results(__return)
*/{

        if (a_len == 0) return -1;
        int res = Integer.MIN_VALUE;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for(int i = 0; i < a_len; i++) {
            res = ((a[i] > res) ? a[i] : res);
        }
        return res;
}