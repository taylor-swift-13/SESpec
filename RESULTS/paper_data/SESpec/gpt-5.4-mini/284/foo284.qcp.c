#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo284(int * arr, int arr_len) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

        int result = 0;
        int min = arr[0];
       
  /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (1 <= i && i <= arr_len + 1) &&
    (0 <= result) &&
    (arr_l[0] >= min) &&
    (forall (k:Z), 0 <= k && k < i => min <= arr_l[k]) &&
    (exists (k:Z), 0 <= k && k < i && arr_l[k] == min) &&
    (forall (k:Z), 0 <= k && k < i => result >= 0)
    */
for (int i = 1; i < arr_len; i++) {
            if (arr[i] > min) {
                result = result > min ? result : min;
            } else {
                min = arr[i];
            }
        }
        return result;
}