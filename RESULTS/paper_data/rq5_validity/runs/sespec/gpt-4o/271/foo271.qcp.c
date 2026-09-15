#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_odd : Z -> Z -> Z -> Z) */
/*@ Extern Coq (last_odd : Z -> Z -> Z -> Z) */
int foo271(int * arr, int arr_len, int arrSize) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

        int result = 0;
        int count = 0;
       
  /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= i) &&
    (0 <= count && count <= i) &&
    (count == count_odd(arr, 0, i)) &&
    ((count % 2 != 0) => (result == last_odd(arr, 0, i))) &&
    (forall (k:Z), 0 <= k && k < i => arr_l[k] == arr_l[k]@pre) &&
    (arrSize == arrSize@pre) &&
    (arr_len == arr_len@pre) &&
    (arr == arr@pre)
    */
for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 != 0) {
            count++;
            if (count % 2 != 0) {
                result = arr[i];
            }
        }
    }
        return result;
}