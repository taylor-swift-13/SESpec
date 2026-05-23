#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo275(int * arr, int arr_len, int n) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

        int sum = 0;
       
  /*0*/ 
 /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= i && i <= arr_len) &&
    (0 <= sum) &&
    (forall (k:Z), 0 <= k && k < arr_len => 0 <= arr_l[k] && arr_l[k] <= 100) &&
    (n == n@pre) &&
    (arr_len == arr_len@pre) &&
    (arr == arr@pre)
    */
for (int i = 0; i < arr_len; i++) {
           
  /*1*/ 
 /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (i >= 0 && i <= arr_len) &&
    (i+1 <= j && j <= arr_len) &&
    (0 <= sum)
    */
for (int j = i + 1; j < arr_len; j++) {
                sum += arr[i] ^ arr[j];
            }
        }
        return sum;
}