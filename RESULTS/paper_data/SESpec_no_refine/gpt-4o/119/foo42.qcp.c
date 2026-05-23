#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo42(int * arr, int arr_len);

int foo42(int * arr, int arr_len) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100
Ensure Results(__return)
*/{

        int n = arr_len;
        if (n < 2) {
            return 1;
        }
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100 &&
    (0 <= i && i <= n) &&
(forall (k:Z), 0 <= k && k < i => arr_l[k] > arr_l[k+1]) &&
(forall (k:Z), i <= k && k < n => arr_l[k] == arr_l[k]@pre
      loop assigns i)
    */
    
    for (int i = 0; i < n; i++) {
        if (arr[i] <= arr[i+1])
            return 0;
    }
        return 1;
}