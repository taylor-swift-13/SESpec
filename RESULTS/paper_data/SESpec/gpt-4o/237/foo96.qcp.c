#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo96(int * arr, int arr_len, int x, int n);

int foo96(int * arr, int arr_len, int x, int n) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100
Ensure Results(__return)
*/{

        int low = 0;
        int high = n - 1;
        int result = -1;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100 &&
    (0 <= low && low <= n && n >= 0) &&
(-1 <= high && high < n) &&
(-1 <= result && result < n) &&
(n == n@pre) &&
(x == x@pre) &&
(arr_len == arr_len@pre) &&
(arr == arr@pre) &&
(forall (k:Z), 0 <= k && k < n => (arr_l[k] == arr_l[k]@pre)) &&
((result != -1) => (arr_l[result] == x)
      loop assigns low, high, result)
    */
    
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) {
            result = mid;
            high = mid - 1;
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
        return result;
}