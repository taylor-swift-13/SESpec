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
    ((0 <= n@pre - 1) => (((result == -1)&&(high == n@pre - 1)&&(low == 0)&&(n == n@pre)&&(x == x@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre)) || (0 <= low && low <= high + 1))) &&
((0 <= n@pre - 1) => (((result == -1)&&(high == n@pre - 1)&&(low == 0)&&(n == n@pre)&&(x == x@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre)) || (high < n))) &&
((0 <= n@pre - 1) => (((result == -1)&&(high == n@pre - 1)&&(low == 0)&&(n == n@pre)&&(x == x@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre)) || (result == -1 || (0 <= result && result < n && arr_l[result] == x)))) &&
((!(0 <= n@pre - 1)) => ((result == -1)&&(high == n@pre - 1)&&(low == 0)&&(n == n@pre)&&(x == x@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre))) &&
(n == n@pre) &&
(x == x@pre) &&
(arr_len == arr_len@pre) &&
(arr == arr@pre) &&
(forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre
          loop assigns result, high, low)
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