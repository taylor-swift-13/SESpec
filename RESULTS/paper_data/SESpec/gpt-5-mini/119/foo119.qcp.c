#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
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
    (0 <= n) &&
    (true)) &&
    ((i < n-1) => (0 <= i && i+1 < n)) &&
    (forall (k:Z), 0 <= k && k < i => arr_l[k] > arr_l[k+1]) &&
    ((!(i < n)) => (forall (k:Z), 0 <= k && k < n-1 => arr_l[k] > arr_l[k+1])) &&
    (forall (k:Z), 0 <= k && k < n => arr_l[k] == arr_l[k]@pre)
    */
for (int i = 0; i < n; i++) {
        if(arr[i] <= arr[i+1])
            return 0;
    }
        return 1;
}