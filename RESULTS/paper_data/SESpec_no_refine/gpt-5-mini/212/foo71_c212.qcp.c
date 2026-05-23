#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo71_c212(int * arr1, int arr1_len, int * arr2, int arr2_len, int n);

int foo71_c212(int * arr1, int arr1_len, int * arr2, int arr2_len, int n) 
/*@
With arr1_l arr2_l
Require store_int_array(arr1, arr1_len, arr1_l) && arr1_len > 0 && arr1_len < 100 && store_int_array(arr2, arr2_len, arr2_l) && arr2_len > 0 && arr2_len < 100
Ensure Results(__return)
*/{

        int i = 0;
        int j = 0;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (i < arr1_len && j < arr2_len) {
            if (arr1[i] < arr2[j]) {
                i++;
            } else if (arr1[i] > arr2[j]) {
                j++;
            } else {
                i++;
                j++;
            }
        }
        return i < arr1_len ? i : j;
}