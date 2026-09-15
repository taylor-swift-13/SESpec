#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo162(int * arr, int arr_len, int n);

int foo162(int * arr, int arr_len, int n) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100
Ensure Results(__return)
*/{

        int i = 0;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100 &&
    (forall (k:Z), 0 <= k && k < i => (arr_l[k] <= 0 || arr_l[k] > n || arr_l[k] == k + 1)) &&
(forall (k:Z), 0 <= k && k < n => (arr_l[k] <= 0 || arr_l[k] > n || arr_l[k] == k + 1 || (0 <= arr_l[k] - 1 < n))
          loop assigns i, arr_l[0..n-1])
    */
    
            while (i < n) {
            if (arr[i] <= 0 || arr[i] > n || arr[i] == i + 1) {
                i++;
            } else {
                int temp = arr[i];
                arr[i] = arr[temp - 1];
                arr[temp - 1] = temp;
            }
        }
       
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100 &&
    ((i < n) => (forall (k:Z), 0 <= k && k < i => arr_l[k] == k + 1)) &&
(forall (k:Z), 0 <= k && k < n => (arr_l[k] <= 0 || arr_l[k] > n || arr_l[k] == k + 1 || (0 <= arr_l[k] - 1 < n))
          loop assigns i)
    */
    
            for (i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
}