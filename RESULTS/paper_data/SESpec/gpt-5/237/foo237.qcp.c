#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (sorted_non_decr : Z -> Z -> Prop) */
int foo237(int * arr, int arr_len, int x, int n) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

        int low = 0;
        int high = n - 1;
        int result = -1;
       
  /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (true)) &&
    (0 <= arr_len) &&
    (0 <= n && n <= arr_len) &&
    (n == n@pre) &&
    (x == x@pre) &&
    (arr_len == arr_len@pre) &&
    (arr == arr@pre) &&
    (forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre) &&
    (sorted_non_decr(arr, n)) &&
    (0 <= low && low <= n) &&
    (-1 <= high && high <= n - 1) &&
    (low <= high + 1) &&
    ((result == -1) || (0 <= result && result < n)) &&
    ((result == -1) || (arr_l[result] == x)) &&
    ((result == -1) || (high < result))
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