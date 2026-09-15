#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo40_c185(int * a, int a_len, int x);

int foo40_c185(int * a, int a_len, int x) 
/*@
With a_l
Require store_int_array(a, a_len, a_l) && a_len > 0 && a_len < 100
Ensure Results(__return)
*/{

        int low = 0, high = a_len - 1;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) && a_len > 0 && a_len < 100 &&
    (x == x@pre) &&
(a_len == a_len@pre) &&
(a == a@pre) &&
(\valid_read(a + (0..a_len-1))) &&
(nondecreasing(a, a_len)) &&
(a_len > 0 && a_len < 100) &&
(-1 <= high && high < a_len) &&
(0 <= low && low <= a_len
          loop assigns high, low)
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