#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (inv_between : Z -> Z -> Z -> Z -> Z) */
/*@ Extern Coq (inv_prefix : Z -> Z -> Z -> Z) */
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
    (0 <= i) &&
    (invCount == inv_prefix(arr, n, i)) &&
    (0 <= invCount) &&
    (forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre) &&
    (n == n@pre) &&
    (arr_len == arr_len@pre) &&
    (arr == arr@pre)
    */
for (int i = 0; i < n; i++) {
            
            /*@
          loop invariant 0 <= i <= n;
          loop invariant i + 1 <= j <= n;
          loop invariant invCount == inv_prefix(arr, n, i) + inv_between(arr, n, i, j);
          loop invariant 0 <= invCount;
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop assigns j, invCount;
            */
            /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= i && i <= n) &&
    (i + 1 <= j && j <= n) &&
    (invCount == inv_prefix(arr, n, i) + inv_between(arr, n, i, j)) &&
    (0 <= invCount) &&
    (forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre)
    */
for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    invCount++;
                }
            }
            
        }
        return invCount;
}