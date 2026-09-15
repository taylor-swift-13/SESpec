#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo167(int * arr, int arr_len, int n, int k);

int foo167(int * arr, int arr_len, int n, int k) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100
Ensure Results(__return)
*/{

        int max1 = arr[0];
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100 &&
    (k == k@pre) &&
(n == n@pre) &&
(arr_len == arr_len@pre) &&
(arr == arr@pre) &&
(array_unchanged{Pre,Here}(arr, arr_len) 
          loop assigns i, max1)
    */
    
        for (int i = 1; i < n; i++) {
            if (arr[i] > max1) {
                max1 = arr[i];
            }
        }
        int res = 0;
       
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100 &&
    ((i < n) => (0 <= i && i < n)) &&
((0 <= i && i <= n) => all_divisible_prefix(arr, 0, i, max1, k)) &&
((0 <= i && i <= n) => res == sum_div_k(arr, 0, i, max1, k)) &&
((!(i < n)) => (res == sum_div_k(arr, 0, n, max1, k))) &&
(array_unchanged{Pre,Here}(arr, arr_len)
          loop assigns i, res)
    */
    
            for (int i = 0; i < n; i++) {
            if ((max1 - arr[i]) % k != 0) {
                return -1;
            } else {
                res += (max1 - arr[i]) / k;
            }
        }
        return res;
}