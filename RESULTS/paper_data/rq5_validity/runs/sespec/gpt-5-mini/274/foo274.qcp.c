#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (sum_even_indices_even_values : Z -> Z -> Z -> Z) */
int foo274(int * arr, int arr_len, int n) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

        int count = 0;
       
  /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= n == n@pre) &&
    (0 <= arr_len == arr_len@pre) &&
    (true)) &&
    (arr == arr@pre) &&
    (0 <= i && i <= n@pre) &&
    (count == sum_even_indices_even_values(arr, 0, i)) &&
    (forall (k:Z), 0 <= k && k < i => 0 <= k && k < arr_len@pre) &&
    ((i >= n@pre) => count == sum_even_indices_even_values(arr, 0, n@pre)) &&
    ((i < n@pre) => ( (i % 2 == 0 && arr_l[i] % 2 == 0) => (count + arr_l[i] == sum_even_indices_even_values(arr, 0, i+1)) )) &&
    ((i < n@pre) => ( (! (i % 2 == 0 && arr_l[i] % 2 == 0)) => (count == sum_even_indices_even_values(arr, 0, i+1)) ))
    */
for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (arr[i] % 2 == 0) {
                count += arr[i];
            }
        }
    }
        return count;
}