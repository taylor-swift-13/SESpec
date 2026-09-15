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
    (iBegin == iBegin@pre) &&
    (iEnd == iEnd@pre) &&
    (a == a@pre) &&
    (b == b@pre) &&
    (a_len == a_len@pre) &&
    (b_len == b_len@pre) &&
    (k == iBegin@pre + (k - iBegin@pre)) &&
    (forall (t:Z), 0 <= t && t < iBegin => a_l[t] == a_l[t]@pre) &&
    (forall (t:Z), iEnd <= t && t < a_len => a_l[t] == a_l[t]@pre) &&
    (k == iBegin => (forall (t:Z), iBegin <= t && t < iEnd => a_l[t] == a_l[t]@pre)) &&
    (k > iBegin => (exists (u:Z), iBegin <= u && u < k && a_l[u] == b_l[u])) &&
    (k - iBegin@pre >= 0) &&
    ((iEnd@pre - iBegin@pre > 0) => (iBegin <= k && k <= iEnd)) &&
    ((!(iEnd@pre - iBegin@pre > 0)) => ((k == iBegin@pre)&&(a_len == a_len@pre)&&(a == a@pre)&&(iEnd == iEnd@pre)&&(iBegin == iBegin@pre)&&(b_len == b_len@pre)&&(b == b@pre))) &&
    (a_len == a_len@pre) &&
    (a == a@pre) &&
    (iEnd == iEnd@pre) &&
    (iBegin == iBegin@pre) &&
    (b_len == b_len@pre) &&
    (b == b@pre) &&
    (forall (t:Z), 0 <= t && t < iBegin => a_l[t] == a_l[t]@pre) &&
    (forall (t:Z), iEnd <= t && t < a_len => a_l[t] == a_l[t]@pre)
    */
while (iEnd - k > 0) {
            a[k] = b[k];
            k = k + 1 ;
        }
}