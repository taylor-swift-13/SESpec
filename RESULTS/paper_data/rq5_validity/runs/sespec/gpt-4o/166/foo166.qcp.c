#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (is_even : Z -> Prop) */
int foo166(int * a, int a_len, int n) 
/*@
With a_l
Require store_int_array(a, a_len, a_l)
Ensure Results(__return)
*/{

        if (a == NULL) {
            return -1;
        }
        if (a_len == 1) {
            return 0;
        }

        int evenPairCount = 0;
       
  /*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) &&
    (0 <= i && i <= a_len) &&
    (evenPairCount >= 0) &&
    (forall (k:Z), forall (l:Z), 0 <= k && k < l && l < i => (is_even(a_l[k] ^ a_l[l]) => evenPairCount >= 0)) &&
    (forall (k:Z), 0 <= k && k < a_len => a_l[k] == a_l[k]@pre)
    */
for (int i = 0; i < a_len; i++) {

        /*@
          loop invariant i + 1 <= j <= a_len;
          loop invariant evenPairCount >= 0;
          loop invariant \forall integer k, l; 0 <= k < l < i || 
                         (k == i && i + 1 <= l < j) ==> 
                         (is_even(a[k] ^ a[l]) ==> evenPairCount >= 0);
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
          loop assigns j, evenPairCount;
        */
        /*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) &&
    (i + 1 <= j && j <= a_len) &&
    (evenPairCount >= 0) &&
    (forall (k:Z), forall (l:Z), 0 <= k && k < l && l < i || (k == i && i + 1 <= l && l < j) => (is_even(a_l[k] ^ a_l[l]) => evenPairCount >= 0)) &&
    (forall (k:Z), 0 <= k && k < a_len => a_l[k] == a_l[k]@pre)
    */
for (int j = i + 1; j < a_len; j++) {
            int x = a[i];
            int y = a[j];
            int v = x ^ y;
            if ((v & 1) == 0) {
                evenPairCount++;
            }
        }
    }
        return evenPairCount;
}