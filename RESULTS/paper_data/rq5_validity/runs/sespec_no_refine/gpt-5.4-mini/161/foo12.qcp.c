#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo12(int * a, int a_len, int * b, int b_len);

int foo12(int * a, int a_len, int * b, int b_len) 
/*@
With a_l b_l
Require store_int_array(a, a_len, a_l) && a_len > 0 && a_len < 100 && store_int_array(b, b_len, b_l) && b_len > 0 && b_len < 100
Ensure Results(__return)
*/{

        if(a_len != b_len) {
	    return 0;
        }

       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for(int i = 0; i < a_len; i++) {
            if(a[i] != b[i]) {
                return 0;
            }
        }

        return 1;
}