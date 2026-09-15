#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_eq : Z -> Z -> Z -> Z -> Z) */
int foo182(int * a, int a_len, int x) 
/*@
With a_l
Require store_int_array(a, a_len, a_l)
Ensure Results(__return)
*/{

        int low = 0;
        int high = a_len - 1;
        int mid = 0;
       
  /*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) &&
    (0 <= low && low <= a_len) &&
    (-1 <= high && high < a_len) &&
    (low <= high + 1) &&
    (forall (k:Z), 0 <= k && k < a_len => a_l[k] == a_l[k]@pre) &&
    ((low <= high) => (low <= ((low + high) / 2) <= high)) &&
    (x == x@pre) &&
    (a_len == a_len@pre) &&
    (a == a@pre)
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