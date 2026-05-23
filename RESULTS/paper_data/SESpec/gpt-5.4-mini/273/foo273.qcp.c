#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (prod : Z -> Z -> Z -> Z) */
/*@ Extern Coq (suffixsum : Z -> Z -> Z -> Z) */
/*@ Extern Coq (contrib : Z -> Z -> Z -> Z) */
int foo273(int * arr, int arr_len, int n) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

        int sum = 0;
       
  /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= i && i <= n) &&
    (0 <= sum) &&
    (forall (k:Z), 0 <= k && k < i => 0 <= arr_l[k] && arr_l[k] <= 100)
    */
for (int i = 0; i < n; i++) {
            int product = 1;
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant i <= j <= n;
          loop invariant product >= 0;
          loop invariant sum >= 0;
          loop invariant \forall integer k; i <= k < j ==> 0 <= arr[k] <= 100;
          loop assigns product, sum, j;
            */
            /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (i <= j && j <= n) &&
    (product >= 0) &&
    (sum >= 0) &&
    (forall (k:Z), i <= k && k < j => 0 <= arr_l[k] && arr_l[k] <= 100)
    */
for (int j = i; j < n; j++) {
                product *= arr[j];
                sum += product;
            }
            
        }
        return sum;
}