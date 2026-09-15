#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo37_c182(int * a, int a_len, int x);

int foo37_c182(int * a, int a_len, int x) 
/*@
With a_l
Require store_int_array(a, a_len, a_l) && a_len > 0 && a_len < 100
Ensure Results(__return)
*/{

        int low = 0;
        int high = a_len - 1;
        int mid = 0;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) && a_len > 0 && a_len < 100 &&
    ((0 <= a_len@pre - 1) => (0 <= low && low <= a_len@pre)) &&
((0 <= a_len@pre - 1) => (-1 <= high && high <= a_len@pre - 1)) &&
((0 <= a_len@pre - 1) => ( (mid == 0 && high == a_len@pre-1 && low == 0 && x == x@pre && a_len == a_len@pre && a == a@pre) || (low <= high + 1) )) &&
((!(0 <= a_len@pre - 1)) => ((mid == 0)&&(high == a_len@pre - 1)&&(low == 0)&&(x == x@pre)&&(a_len == a_len@pre)&&(a == a@pre))) &&
(x == x@pre) &&
(a_len == a_len@pre) &&
(a == a@pre) &&
(forall (k:Z), 0 <= k && k < a_len@pre => a_l[k] == a_l[k]@pre
          loop assigns mid, low, high)
    */
    
            while (low <= high) {
            mid = (low + high) / 2;
            if (a[mid] == x) {
                if (mid == a_len - 1 || a[mid + 1] != x) {
                    return mid;
                } else {
                    low = mid + 1;
                }
            } else if (a[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
}