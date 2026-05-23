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
/*@ Inv emp */ /*0*/ 
 for (int i = 0; i < n; i++) {
            int product = 1;
           
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv emp */ /*1*/ 
 for (int j = i; j < n; j++) {
                product *= arr[j];
                sum += product;
            }
        }
        return sum;
}