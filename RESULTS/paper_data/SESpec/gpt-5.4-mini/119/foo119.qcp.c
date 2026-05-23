#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (strict_decreasing_prefix : Z -> Z -> Z -> Prop) */
int foo119(int * arr, int arr_len) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

        int n = arr_len;
        if (n < 2) {
            return 1;
        }
       
  /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= i && i <= n) &&
    (strict_decreasing_prefix(arr, 0, i)) &&
    (forall (k:Z), 0 <= k && k < i => (k + 1 < n => arr_l[k] > arr_l[k+1])) &&
    (forall (k:Z), 0 <= k && k < n => arr_l[k] == arr_l[k]@pre) &&
    ((i < n) => (i + 1 <= n)) &&
    ((i == n) => strict_decreasing_prefix(arr, 0, n)) &&
    ((i == n) => (forall (k:Z), 0 <= k && k < n - 1 => arr_l[k] > arr_l[k+1])) &&
    ((i > 0) => arr_l[i-1] > arr_l[i])
    */
for (int i = 0; i < n; i++) {
            if(arr[i] <= arr[i+1])
                return 0;
        }
        return 1;
}