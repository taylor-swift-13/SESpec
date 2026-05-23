#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (count_eq : Z -> Z -> Z -> Z -> Z) */

int foo162(int * arr, int arr_len, int n) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

        int i = 0;
       
  /*0*/ 
 /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= i) &&
    (i <= n) &&
    (0 <= n) &&
    (0 <= arr_len) &&
    (forall (k:Z), 0 <= k && k < arr_len => true) &&
    (forall (k:Z), 0 <= k && k < i => (arr_l[k] <= 0 || arr_l[k] > n || arr_l[k] == k + 1)) &&
    ((0 < n@pre) => (i >= 0 && i <= n)) &&
    ((!(0 < n@pre)) => ((i == 0) && (n == n@pre) && (arr_len == arr_len@pre) && (arr == arr@pre))) &&
    (n == n@pre) &&
    (arr_len == arr_len@pre)
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
       
  /*1*/ 
 /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= i && i <= n) &&
    (forall (k:Z), 0 <= k && k < i => arr_l[k] == k + 1) &&
    (forall (k:Z), 0 <= k && k < arr_len => 0 <= arr_l[k] && arr_l[k] <= 100) &&
    (forall (v:Z), 1 <= v && v <= n => count_eq(arr, 0, arr_len, v) == \at(count_eq(arr, 0, arr_len, v), Pre))
    */
for (i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
}