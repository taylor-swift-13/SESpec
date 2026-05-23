#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (sum_xor_with : Z -> Z -> Z -> Z -> Z) */
/*@ Extern Coq (sum_pairs_before_i : Z -> Z -> Z -> Z) */
int foo275(int * arr, int arr_len, int n) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

        int sum = 0;
       
  /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (i + 1 <= j && j <= arr_len)
    */
for (int i = 0; i < arr_len; i++) {

        /*@
          loop invariant i + 1 <= j <= arr_len;
        */
        for (int j = i + 1; j < arr_len; j++) {
            sum += arr[i] ^ arr[j];
        }
    }
        return sum;
}