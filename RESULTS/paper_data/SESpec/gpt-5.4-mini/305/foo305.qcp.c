#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo305(int * arr, int arr_len, int n) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

        int left = 0, right = n - 1;
       
  /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= left) &&
    (right < n) &&
    (left <= right + 1) &&
    (arr_len == arr_len@pre) &&
    (n == n@pre) &&
    (arr == arr@pre) &&
    (forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre) &&
    ((0 < n@pre - 1) => (0 <= left && left <= right + 1)) &&
    ((0 < n@pre - 1) => (right < n@pre)) &&
    ((!(0 < n@pre - 1)) => ((right == n@pre - 1)&&(left == 0)&&(n == n@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre)))
    */
while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < arr[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
}