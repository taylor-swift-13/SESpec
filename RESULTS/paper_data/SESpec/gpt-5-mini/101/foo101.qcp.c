#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
void foo101(int * b, int b_len, int iBegin, int iEnd, int * a, int a_len) 
/*@
With b_l a_l
Require store_int_array(b, b_len, b_l) && store_int_array(a, a_len, a_l)
Ensure emp
*/{

        int k = iBegin;

       
  /*@ Inv
    exists  b_l a_l,    
    store_int_array(b, b_len, b_l) && store_int_array(a, a_len, a_l) &&
    (0 <= iBegin == iBegin@pre) &&
    (0 <= iEnd == iEnd@pre) &&
    (0 <= a_len == a_len@pre) &&
    (0 <= b_len == b_len@pre) &&
    (0 <= k && k <= iEnd) &&
    (0 <= iBegin && iBegin <= k && k <= a_len) &&
    (forall (p:Z), 0 <= p && p < a_len && !(iBegin <= p && p < k) => a_l[p] == a_l[p]@pre) &&
    (a_len == a_len@pre) &&
    (b_len == b_len@pre) &&
    (iBegin == iBegin@pre) &&
    (iEnd == iEnd@pre) &&
    (b == b@pre)
    */
while (iEnd - k > 0) {
        a[k] = b[k];
        k = k + 1 ;
    }
}