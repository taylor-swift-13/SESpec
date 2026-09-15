#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo101(int * b, int b_len, int iBegin, int iEnd, int * a, int a_len);

void foo101(int * b, int b_len, int iBegin, int iEnd, int * a, int a_len) 
/*@
With b_l a_l
Require store_int_array(b, b_len, b_l) && b_len > 0 && b_len < 100 && store_int_array(a, a_len, a_l) && a_len > 0 && a_len < 100
Ensure emp
*/{

        int k = iBegin;

       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (iEnd - k > 0) {
            a[k] = b[k];
            k = k + 1 ;
        }
}