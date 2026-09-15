#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (prefix_max : Z -> Z -> Z -> Z) */
int foo131(int * a, int a_len) 
/*@
With a_l
Require store_int_array(a, a_len, a_l)
Ensure Results(__return)
*/{

        if (a_len == 0) return -1;
        int res = INT_MIN;
       
  /*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) &&
    (0 <= i && i <= a_len) &&
    (res == prefix_max(a, 0, i)) &&
    (forall (k:Z), 0 <= k && k < a_len => a_l[k] == a_l[k]@pre) &&
    (forall (k:Z), 0 <= k && k < i => a_l[k] <= res)
    */
for(int i = 0; i < a_len; i++) {
        res = ((a[i] > res) ? a[i] : res);
    }
        return res;
}