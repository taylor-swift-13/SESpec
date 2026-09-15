#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo157(int * arr, int arr_len, int n) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

        int *mpis = (int *)malloc(sizeof(int) * (n));
int mpis_len = n;
       
  /*0*/ 
 /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= i && i <= n)
    */
for (int i = 0; i < n; i++) {
            mpis[i] = arr[i];
        }
       
  /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (1 <= i && i <= n)
    */
for (int i = 1; i < n; i++) {
            
            /*@
              loop invariant 0 <= j <= i;
              loop assigns j, mpis[i];
            */
            /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= j && j <= i)
    */
for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j] && mpis[i] < (mpis[j] * arr[i])) {
                    mpis[i] = mpis[j] * arr[i];
                }
            }
            
        }
        int max = mpis[0];
       
  /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (1 <= i && i <= n) &&
    (forall (k:Z), 0 <= k && k < i => max >= mpis[k]) &&
    (exists (k:Z), 0 <= k && k < i && max == mpis[k])
    */
for (int i = 1; i < n; i++) {
            if (mpis[i] > max) {
                max = mpis[i];
            }
        }
        return max;
}