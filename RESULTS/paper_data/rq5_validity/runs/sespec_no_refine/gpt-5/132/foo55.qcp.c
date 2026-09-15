#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo55(int * a, int a_len);

int foo55(int * a, int a_len) 
/*@
With a_l
Require store_int_array(a, a_len, a_l) && a_len > 0 && a_len < 100
Ensure Results(__return)
*/{

        if (a_len == 0) return -1;
        int res = Integer.MIN_VALUE;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) && a_len > 0 && a_len < 100 &&
    (0 <= i && i <= a_len) &&
(forall (k:Z), 0 <= k && k < a_len => a_l[k] == a_l[k]@pre) &&
(res == min_prefix(a, i)
          loop assigns i, res)
    */
    
        for(int i = 0; i < a_len; i++) {
            res = ((a[i] < res) ? a[i] : res);
        }
        return res;
}