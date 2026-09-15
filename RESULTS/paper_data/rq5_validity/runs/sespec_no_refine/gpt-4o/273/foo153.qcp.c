#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo153(int * arr, int arr_len, int n);

int foo153(int * arr, int arr_len, int n) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100
Ensure Results(__return)
*/{

        int sum = 0;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100 &&
    (0 <= i && i <= n) &&
(n == n@pre) &&
(arr_len == arr_len@pre) &&
(arr == arr@pre
      loop assigns i, sum)
    */
    
    for (int i = 0; i < n; i++) {
        int product = 1;

        /*@
          loop invariant i <= j <= n;
          loop invariant n == \at(n, Pre);
          loop invariant arr_len == \at(arr_len, Pre);
          loop invariant arr == \at(arr, Pre);
          loop assigns j, product, sum;
        */
        for (int j = i; j < n; j++) {
            product *= arr[j];
            sum += product;
        }
    }
        return sum;
}