#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo8_c157(int * arr, int arr_len, int n);

int foo8_c157(int * arr, int arr_len, int n) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100
Ensure Results(__return)
*/{

        int *mpis = (int *)malloc(sizeof(int) * (n));
int mpis_len = n;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for (int i = 0; i < n; i++) {
            mpis[i] = arr[i];
        }
       
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv emp */ /*1*/ 
 for (int i = 1; i < n; i++) {
           
  /*@ Print user assertion at number LoopEntry_2*/ 
/*@ Inv emp */ /*2*/ 
 for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j] && mpis[i] < (mpis[j] * arr[i])) {
                    mpis[i] = mpis[j] * arr[i];
                }
            }
        }
        int max = mpis[0];
       
  /*@ Print user assertion at number LoopEntry_3*/ 
/*@ Inv emp */ /*3*/ 
 for (int i = 1; i < n; i++) {
            if (mpis[i] > max) {
                max = mpis[i];
            }
        }
        return max;
}