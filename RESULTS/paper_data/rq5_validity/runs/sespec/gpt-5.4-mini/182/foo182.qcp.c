#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
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
    (0 <= low) &&
    (high < a_len) &&
    (0 <= mid) &&
    (low <= high + 1) &&
    (0 <= low && high < a_len && (low <= high + 1)) &&
    ((((mid == 0)&&(high == a_len@pre - 1)&&(low == 0)&&(x == x@pre)&&(a_len == a_len@pre)&&(a == a@pre)) || (0 <= low))) &&
    ((((mid == 0)&&(high == a_len@pre - 1)&&(low == 0)&&(x == x@pre)&&(a_len == a_len@pre)&&(a == a@pre)) || (high < a_len))) &&
    ((((mid == 0)&&(high == a_len@pre - 1)&&(low == 0)&&(x == x@pre)&&(a_len == a_len@pre)&&(a == a@pre)) || (0 <= mid))) &&
    ((!(0 <= a_len@pre - 1)) => ((mid == 0)&&(high == a_len@pre - 1)&&(low == 0)&&(x == x@pre)&&(a_len == a_len@pre)&&(a == a@pre))) &&
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