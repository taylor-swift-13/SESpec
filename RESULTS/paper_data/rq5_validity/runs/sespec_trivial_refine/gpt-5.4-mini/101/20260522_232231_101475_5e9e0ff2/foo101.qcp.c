#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (valid_read_range : Z -> Z -> Z -> Prop) */
/*@ Extern Coq (valid_write_range : Z -> Z -> Z -> Prop) */
/*@ Extern Coq (in_bounds : Z -> Z -> Z -> Prop) */

void foo101(int * b, int b_len, int iBegin, int iEnd, int * a, int a_len) 
/*@
With b_l a_l
Require store_int_array(b, b_len, b_l) && store_int_array(a, a_len, a_l)
Ensure emp
*/{

        int k = iBegin;

       
  /*0*/ 
 /*@ Inv
    exists  b_l a_l,    
    store_int_array(b, b_len, b_l) && store_int_array(a, a_len, a_l) &&
    (iBegin <= k && k <= iEnd)
    */
while (iEnd - k > 0) {
            a[k] = b[k];
            k = k + 1 ;
        }
}