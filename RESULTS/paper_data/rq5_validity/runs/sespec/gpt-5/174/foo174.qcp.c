#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo174(int * a, int a_len) 
/*@
With a_l
Require store_int_array(a, a_len, a_l)
Ensure Results(__return)
*/{

        int start = 0;
        int end = a_len - 1;
       
  /*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) &&
    (0 <= start) &&
    (end <= a_len@pre - 1) &&
    (a_len == a_len@pre) &&
    (a == a@pre) &&
    (forall (k:Z), 0 <= k && k < a_len@pre => a_l[k] == a_l[k]@pre) &&
    ((start <= end) => (start <= (start + (end - start) / 2))) &&
    ((start <= end) => ((start + (end - start) / 2) <= end)) &&
    ((start <= end && start < end) => (start + 1 <= end)) &&
    ((0 <= a_len@pre - 1) => (((end == a_len@pre - 1)&&(start == 0)&&(a_len == a_len@pre)&&(a == a@pre)) || (0 <= start))) &&
    ((0 <= a_len@pre - 1) => (((end == a_len@pre - 1)&&(start == 0)&&(a_len == a_len@pre)&&(a == a@pre)) || (start <= a_len@pre))) &&
    ((0 <= a_len@pre - 1) => (((end == a_len@pre - 1)&&(start == 0)&&(a_len == a_len@pre)&&(a == a@pre)) || (-1 <= end))) &&
    ((0 <= a_len@pre - 1) => (((end == a_len@pre - 1)&&(start == 0)&&(a_len == a_len@pre)&&(a == a@pre)) || (end <= a_len@pre - 1))) &&
    ((!(0 <= a_len@pre - 1)) => ((end == a_len@pre - 1)&&(start == 0)&&(a_len == a_len@pre)&&(a == a@pre)))
    */
while (start <= end) {
            int mid = start + (end - start) / 2;
            if (mid < end && a[mid] > a[mid + 1]) {
                return mid + 1;
            } else if (mid > start && a[mid] < a[mid - 1]) {
                return mid;
            }
            if (a[mid] >= a[start]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return 0;
}