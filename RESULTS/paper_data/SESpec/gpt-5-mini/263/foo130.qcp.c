#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo130(int * arr, int arr_len, int n);

int foo130(int * arr, int arr_len, int n) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100
Ensure Results(__return)
*/{

        int start = 0;
        int end = n - 1;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100 &&
    (n == n@pre) &&
(arr_len == arr_len@pre) &&
(arr == arr@pre) &&
(0 <= start && start <= n@pre) &&
(-1 <= end && end <= n@pre - 1) &&
(start <= n@pre) &&
(end < n@pre) &&
(same_array{Pre,Here}(arr, arr_len)
      loop assigns start, end)
    */
    
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == mid) {
            return mid;
        } else if (arr[mid] < mid) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
        return -1;
}