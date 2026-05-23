#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo129(int * a, int a_len, int x);

int foo129(int * a, int a_len, int x) 
/*@
With a_l
Require store_int_array(a, a_len, a_l) && a_len > 0 && a_len < 100
Ensure Results(__return)
*/{

        int left = 0;
        int right = a_len - 1;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) && a_len > 0 && a_len < 100 &&
    (0 <= left && left <= right + 1 <= a_len) &&
(x == x@pre) &&
(a_len == a_len@pre) &&
(a == a@pre) &&
(sorted(a, 0, a_len)) &&
(forall (k:Z), left <= k && k <= right => a_l[k] == x || a_l[k] != x
      loop assigns left, right)
    */
    
    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == x) {
            return mid;
        } else if (a[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
        return left;
}