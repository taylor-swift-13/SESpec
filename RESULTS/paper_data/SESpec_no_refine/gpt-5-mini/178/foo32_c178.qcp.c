#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo32_c178(int * arr1, int arr1_len, int * arr2, int arr2_len, int m, int n, int k);

int foo32_c178(int * arr1, int arr1_len, int * arr2, int arr2_len, int m, int n, int k) 
/*@
With arr1_l arr2_l
Require store_int_array(arr1, arr1_len, arr1_l) && arr1_len > 0 && arr1_len < 100 && store_int_array(arr2, arr2_len, arr2_l) && arr2_len > 0 && arr2_len < 100
Ensure Results(__return)
*/{

        int i = 0;
        int j = 0;

       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for (int count = 0; count < k; count++) {
            if (i < m && (j >= n || arr1[i] <= arr2[j])) {
                if (count == k - 1) {
                    return arr1[i];
                }
                i++;
            } else {
                if (count == k - 1) {
                    return arr2[j];
                }
                j++;
            }
        }
        return -1;
}