#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (is_peak : Z -> Z -> Z -> Prop) */
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
    (n == n@pre) &&
    (arr_len == arr_len@pre) &&
    (arr == arr@pre) &&
    (forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre) &&
    (0 <= left || n == 0) &&
    (-1 <= right && right < n) &&
    (left <= right || n == 0) &&
    (n == 0 => (left == 0 && right == -1)) &&
    (!(left < right) => (left == right || n == 0)) &&
    (n > 0 => (0 <= left && left < n))
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