#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (prod_pref : Z -> Z -> Z -> Z) */
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
    (forall (k:Z), 0 <= k && k < arr_len => 0 <= arr_l[k] && arr_l[k] <= 100) &&
    (forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre) &&
    ((i < n@pre) => (0 <= i && i < n)) &&
    (n == n@pre) &&
    (arr_len == arr_len@pre) &&
    (arr == arr@pre) &&
    (forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre)
    */
for (int i = 0; i < n; i++) {
            int product = 1;
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= n;
          loop invariant i <= j <= n;
          loop invariant product == prod_pref(arr, i, j);
          loop assigns product, sum, j;
            */
            /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= i && i <= n) &&
    (i <= j && j <= n) &&
    (product == prod_pref(arr, i, j))
    */
for (int j = i; j < n; j++) {
                product *= arr[j];
                sum += product;
            }
            
        }
        return sum;
}