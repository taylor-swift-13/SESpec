#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo95(int * arr, int arr_len, int x, int n);

int foo95(int * arr, int arr_len, int x, int n) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100
Ensure Results(__return)
*/{

        int i = 0;
        int j = n - 1;
        int result = -1;

       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100 &&
    (0 <= i && i <= n) &&
(-1 <= j && j < n) &&
(-1 <= result && result < n) &&
(n == n@pre) &&
(x == x@pre) &&
(arr_len == arr_len@pre) &&
(arr == arr@pre) &&
(sorted(arr, 0, arr_len)
      loop assigns i, j, result)
    */
    
    while (i <= j) {
        int mid = (i + j) / 2;
        if (arr[mid] == x) {
            result = mid;
            i = mid + 1;
        } else if (arr[mid] < x) {
            i = mid + 1;
        } else {
            j = mid - 1;
        }
    }

        return result;
}