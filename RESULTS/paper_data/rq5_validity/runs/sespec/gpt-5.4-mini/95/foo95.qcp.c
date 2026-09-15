#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
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
    (0 <= i && i <= a_len) &&
    (b_len == a_len) &&
    (forall (k:Z), 0 <= k && k < i => a_l[k] == b_l[k]) &&
    (forall (k:Z), 0 <= k && k < i => a_l[k] == a_l[k]@pre) &&
    (forall (k:Z), 0 <= k && k < i => b_l[k] == b_l[k]@pre) &&
    ((!(i < a_len)) => (forall (k:Z), 0 <= k && k < a_len => a_l[k] == b_l[k]))
    */
for(int i = 0; i < a_len; i++) {
            if(a[i] != b[i]) {
                return 0;
            }
        }

        return 1;
}