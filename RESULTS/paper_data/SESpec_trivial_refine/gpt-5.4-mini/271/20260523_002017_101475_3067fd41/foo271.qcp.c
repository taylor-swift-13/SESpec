#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo271(int * arr, int arr_len, int arrSize) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

        int result = 0;
        int count = 0;
       
  /*0*/ 
 /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= i && i <= arrSize) &&
    (0 <= count && count <= i) &&
    (count <= arrSize) &&
    (count == ( \numof int k 0 <= k && k < i && arr_l[k] % 2 != 0 )) &&
    (result == 0 || (exists (j:Z), 0 <= j && j < i && arr_l[j] % 2 != 0 && result == arr_l[j]))
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