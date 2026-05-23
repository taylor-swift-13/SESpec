#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (sorted : Z -> Z -> Prop) */

int foo185(int * a, int a_len, int x) 
/*@
With a_l
Require store_int_array(a, a_len, a_l)
Ensure Results(__return)
*/{

        int low = 0, high = a_len - 1;
       
  /*0*/ 
 /*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) &&
    (PLACE_HOLDER_SUPPLEMENTARY_INVARIANTS) &&
    (0 <= low && low <= a_len) &&
    (-1 <= high && high < a_len) &&
    (low <= high + 1) &&
    (forall (i:Z), 0 <= i && i < low => a_l[i] < x) &&
    (forall (i:Z), high < i && i < a_len => a_l[i] >= x)
    */
while (low <= high) {
            int mid = low + (high - low) / 2;
            if (a[mid] == x) {
                if (mid == 0 || a[mid - 1] != x) {
                    return mid;
                } else {
                    high = mid - 1;
                }
            } else if (a[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
}