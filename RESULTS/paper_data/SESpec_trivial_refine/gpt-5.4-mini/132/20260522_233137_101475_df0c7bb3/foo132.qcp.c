#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (lower_bound : Z -> Z -> Z -> Prop) */

int foo132(int * a, int a_len) 
/*@
With a_l
Require store_int_array(a, a_len, a_l)
Ensure Results(__return)
*/{

        if (a_len == 0) return -1;
        int res = INT_MIN;
       
  /*0*/ 
 /*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) &&
    (0 <= i && i <= a_len) &&
    (forall (j:Z), 0 <= j && j < i => res <= a_l[j])
    */
for(int i = 0; i < a_len; i++) {
            res = ((a[i] < res) ? a[i] : res);
        }
        return res;
}