#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (product_prefix : Z -> Z -> Z -> Z) */

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
    (0 <= i && i <= n) &&
    (forall (k:Z), 0 <= k && k < i => mpis[k] == arr_l[k]) &&
    (forall (k:Z), i <= k && k < n => mpis[k] == 0)
    */
for (int i = 0; i < n; i++) {
            mpis[i] = arr[i];
        }
       
  /*1*/ 
 /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (1 <= i && i <= n) &&
    (forall (k:Z), 0 <= k && k < i => forall (j:Z), 0 <= j && j < k => (arr_l[k] > arr_l[j] && mpis[k] < mpis[j] * arr_l[k]) => mpis[k] == mpis[j] * arr_l[k]) &&
    (forall (k:Z), 0 <= k && k < i => mpis[k] >= arr_l[k]) &&
    (forall (k:Z), 0 <= k && k < i => mpis[k] <= product_prefix(arr, 0, k + 1))
    */
for (int i = 1; i < n; i++) {
           
  /*2*/ 
 /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= j && j <= i) &&
    (forall (k:Z), 0 <= k && k < i => (arr_l[k] > arr_l[j] && mpis[k] < mpis[j] * arr_l[k]) => mpis[k] == mpis[j] * arr_l[k]) &&
    (forall (k:Z), 0 <= k && k < i => mpis[k] >= arr_l[k]) &&
    (forall (k:Z), 0 <= k && k < i => mpis[k] <= product_prefix(arr, 0, k + 1))
    */
for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j] && mpis[i] < (mpis[j] * arr[i])) {
                    mpis[i] = mpis[j] * arr[i];
                }
            }
        }
        int max = mpis[0];
       
  /*3*/ 
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