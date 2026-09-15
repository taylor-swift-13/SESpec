#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo20(int * b, int b_len, int iBegin, int iEnd, int * a, int a_len);

void foo20(int * b, int b_len, int iBegin, int iEnd, int * a, int a_len) 
/*@
With b_l a_l
Require store_int_array(b, b_len, b_l) && b_len > 0 && b_len < 100 && store_int_array(a, a_len, a_l) && a_len > 0 && a_len < 100
Ensure emp
*/{

        int k = iBegin;

       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  b_l a_l,    
    store_int_array(b, b_len, b_l) && b_len > 0 && b_len < 100 && store_int_array(a, a_len, a_l) && a_len > 0 && a_len < 100 &&
    ((iEnd@pre - iBegin@pre > 0) => (iBegin <= k && k <= iEnd)) &&
((iEnd@pre - iBegin@pre > 0) => (forall (j:Z), k <= j && j < iEnd => a_l[j] == a_l[j]@pre)) &&
((iEnd@pre - iBegin@pre > 0) => (forall (j:Z), 0 <= j && j < a_len => (j < iBegin || j >= iEnd) => a_l[j] == a_l[j]@pre)) &&
((!(iEnd@pre - iBegin@pre > 0)) => ((k == iBegin@pre)&&(a_len == a_len@pre)&&(a == a@pre)&&(iEnd == iEnd@pre)&&(iBegin == iBegin@pre)&&(b_len == b_len@pre)&&(b == b@pre))) &&
(a_len == a_len@pre) &&
(a == a@pre) &&
(iEnd == iEnd@pre) &&
(iBegin == iBegin@pre) &&
(b_len == b_len@pre) &&
(b == b@pre) &&
((iEnd@pre - iBegin@pre > 0) => (forall (j:Z), 0 <= j && j < a_len => (j < iBegin || j >= k) => a_l[j] == a_l[j]@pre)
          loop assigns a_l[iBegin..iEnd-1], k)
    */
    
            while (iEnd - k > 0) {
            a[k] = b[k];
            k = k + 1 ;
        }
}