#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo263(int * arr, int arr_len, int n) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

        int start = 0;
        int end = n - 1;
       
  /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= start && start <= n@pre) &&
    (-1 <= end && end < n@pre) &&
    (start <= end + 1) &&
    (forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre) &&
    ((0 <= n@pre - 1) => (start <= end + 1)) &&
    ((0 <= n@pre - 1) => (((end == n@pre - 1)&&(start == 0)&&(n == n@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre)) || (0 <= start && start <= n@pre))) &&
    ((0 <= n@pre - 1) => (((end == n@pre - 1)&&(start == 0)&&(n == n@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre)) || (-1 <= end && end < n@pre))) &&
    ((!(0 <= n@pre - 1)) => ((end == n@pre - 1)&&(start == 0)&&(n == n@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre))) &&
    (n == n@pre) &&
    (arr_len == arr_len@pre) &&
    (arr == arr@pre) &&
    (forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre)
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