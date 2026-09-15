#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_inversions : Z -> Z -> Z -> Z) */
int foo253(int * arr, int arr_len, int n) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

        int invCount = 0;

       
  /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= i && i <= n) &&
    (invCount >= 0)
    */
for (int i = 0; i < n; i++) {

        /*@
          loop invariant i + 1 <= j <= n;
          loop invariant invCount >= 0;
          loop assigns j, invCount;
        */
        /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (i + 1 <= j && j <= n) &&
    (invCount >= 0)
    */
for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                invCount++;
            }
        }

    }
        return invCount;
}