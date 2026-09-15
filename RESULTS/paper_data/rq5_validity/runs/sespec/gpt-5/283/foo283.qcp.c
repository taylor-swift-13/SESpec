#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_pairs : Z -> Z -> Z) */
int foo283(int * arr, int arr_len, int n) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

        int i = 0;
       
  /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= i && i <= n) &&
    (i % 2 == 0) &&
    (forall (k:Z), 0 <= k && k < i => arr_l[k] == arr_l[k]@pre) &&
    (forall (k:Z), i <= k && k < n => arr_l[k] == arr_l[k]@pre) &&
    (count_pairs(arr, i) == i / 2) &&
    ((i <= n - 1) => (n - i == 0 || n - i >= 1)) &&
    ((i < n - 1) => (i + 1 < n)) &&
    ((0 < n@pre - 1) => (0 <= i && i <= n)) &&
    ((!(0 < n@pre - 1)) => ((i == 0)&&(n == n@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre))) &&
    (n == n@pre) &&
    (arr_len == arr_len@pre) &&
    (arr == arr@pre) &&
    (forall (k:Z), 0 <= k && k < n => arr_l[k] == arr_l[k]@pre)
    */
while (i < n - 1) {
            if (arr[i] == arr[i + 1]) {
                i += 2;
            } else {
                return arr[i];
            }
        }
        return arr[n - 1];
}