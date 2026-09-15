#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (max_prefix : Z -> Z -> Z -> Z) */
/*@ Extern Coq (sum_differences : Z -> Z -> Z -> Z -> Z -> Z) */
int foo167(int * arr, int arr_len, int n, int k) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

        int max1 = arr[0];
       
  /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (1 <= i && i <= n) &&
    (forall (j:Z), 0 <= j && j < i => max1 >= arr_l[j]) &&
    (max1 == max_prefix(arr, 0, i)) &&
    (forall (j:Z), 0 <= j && j < arr_len => arr_l[j] == arr_l[j]@pre)
    */
for (int i = 1; i < n; i++) {
        if (arr[i] > max1) {
            max1 = arr[i];
        }
    }
        int res = 0;
       
  /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= i && i <= n) &&
    (forall (j:Z), 0 <= j && j < arr_len => arr_l[j] == arr_l[j]@pre)
    */
for (int i = 0; i < n; i++) {
        if ((max1 - arr[i]) % k != 0) {
            return -1;
        } else {
            res += (max1 - arr[i]) / k;
        }
    }
        return res;
}