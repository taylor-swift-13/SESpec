#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo273(int * arr, int arr_len, int n) 
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
    (0 <= n) &&
    (n == n@pre) &&
    (0 <= arr_len) &&
    (arr_len == arr_len@pre) &&
    (forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre) &&
    (0 <= i && i <= n@pre) &&
    ((i < n@pre) => (0 <= sum && sum <= 100 * (i*(i+1)/2))) &&
    ((i < n@pre) => (exists (p:Z), 0 <= p && p < i)) &&
    ((!(i < n@pre)) => (sum == 0 && n == n@pre && arr_len == arr_len@pre && arr == arr@pre))
    */
for (int i = 0; i < n; i++) {
            int product = 1;
           
  /*1*/ 
 /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (i >= 0 && n >= 0) &&
    (i <= n) &&
    (j >= i && j <= n) &&
    (forall (k:Z), j <= k && k < n => true) &&
    (forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre)
    */
for (int j = i; j < n; j++) {
                product *= arr[j];
                sum += product;
            }
        }
        return sum;
}