#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo183(int * arr, int arr_len, int n) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

        if (n == 0) {
            return 0;
        }
        int left = 0, right = n - 1;
       
  /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (left >= 0) &&
    (right < n) &&
    ((n > 0) => left <= right + 1) &&
    (arr_len == arr_len@pre) &&
    (n == n@pre) &&
    (arr == arr@pre) &&
    (forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre) &&
    ((0 < n@pre - 1) => (((right == n@pre - 1)&&(left == 0)&&(n == n@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre)) || (0 <= left && left <= right))) &&
    ((0 < n@pre - 1) => (((right == n@pre - 1)&&(left == 0)&&(n == n@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre)) || (0 <= right && left <= right))) &&
    ((!(0 < n@pre - 1)) => ((right == n@pre - 1)&&(left == 0)&&(n == n@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre)))
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