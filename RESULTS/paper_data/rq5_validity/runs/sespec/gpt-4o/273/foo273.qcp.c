#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (prod : Z -> Z -> Z -> Z) */
/*@ Extern Coq (nested_sum : Z -> Z -> Z -> Z) */
/*@ Extern Coq (total_sum : Z -> Z -> Z -> Z) */
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
    (n == n@pre) &&
    (arr_len == arr_len@pre) &&
    (arr == arr@pre)
    */
for (int i = 0; i < n; i++) {
        int product = 1;

        /*@
          loop invariant i <= j <= n;
          loop invariant product == prod(arr, i, j);
          loop assigns j, product, sum;
        */
        /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (i <= j && j <= n) &&
    (product == prod(arr, i, j))
    */
for (int j = i; j < n; j++) {
            product *= arr[j];
            sum += product;
        }
    }
        return sum;
}