#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (arrays_equal : Z -> Z -> Z -> Prop) */
int foo95(int * a, int a_len, int * b, int b_len) 
/*@
With a_l b_l
Require store_int_array(a, a_len, a_l) && store_int_array(b, b_len, b_l)
Ensure Results(__return)
*/{

        if(a_len != b_len) {
	    return 0;
        }

       
  /*@ Inv
    exists  a_l b_l,    
    store_int_array(a, a_len, a_l) && store_int_array(b, b_len, b_l) &&
    (0 <= i) &&
    (forall (k:Z), 0 <= k && k < i => a_l[k] == b_l[k])
    */
for(int i = 0; i < a_len; i++) {
            if(a[i] != b[i]) {
                return 0;
            }
        }

        return 1;
}