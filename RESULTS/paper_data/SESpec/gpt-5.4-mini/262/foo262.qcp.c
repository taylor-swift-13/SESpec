#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo262(int * a, int a_len, int x) 
/*@
With a_l
Require store_int_array(a, a_len, a_l)
Ensure Results(__return)
*/{

        int left = 0;
        int right = a_len - 1;
       
  /*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) &&
    (0 <= left && left <= a_len) &&
    (-1 <= right && right < a_len) &&
    (left <= right + 1) &&
    ((0 <= a_len@pre - 1) => ((left == 0 && right == a_len@pre - 1 && x == x@pre && a_len == a_len@pre && a == a@pre) || (0 <= left && left <= a_len))) &&
    ((0 <= a_len@pre - 1) => ((left == 0 && right == a_len@pre - 1 && x == x@pre && a_len == a_len@pre && a == a@pre) || (-1 <= right && right < a_len))) &&
    ((!(0 <= a_len@pre - 1)) => (right == a_len@pre - 1 && left == 0 && x == x@pre && a_len == a_len@pre && a == a@pre)) &&
    (x == x@pre) &&
    (a_len == a_len@pre) &&
    (a == a@pre) &&
    (forall (k:Z), 0 <= k && k < a_len => a_l[k] == a_l[k]@pre)
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