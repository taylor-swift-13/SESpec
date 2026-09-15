#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo38(int * arr, int arr_len, int n);

int foo38(int * arr, int arr_len, int n) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100
Ensure Results(__return)
*/{

        if (n == 0) {
            return 0;
        }
        int left = 0, right = n - 1;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100 &&
    (left == 0 || (exists (L:Z), 0 < L && L <= n@pre - 1 && 0 <= L && L <= right && left == L)) &&
(right == n@pre - 1 || (exists (R:Z), 0 <= R && R < n@pre - 1 && left <= R && right == R)) &&
((!(0 < n@pre - 1)) => ((right == n@pre - 1)&&(left == 0)&&(n == n@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre))) &&
(n == n@pre) &&
(arr_len == arr_len@pre) &&
(arr == arr@pre) &&
(unchanged_arr(arr, arr_len, arr@pre)
          loop assigns left, right)
    */
    
            while (left < right) {
            if (arr[left] < arr[right]) {
                return left + 1;
            }
            int mid = (left + right) / 2;
            if (arr[mid] > arr[left]) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left + 1;
}