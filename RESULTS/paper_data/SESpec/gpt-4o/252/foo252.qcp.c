#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (count_pairs : Z -> Z -> Z -> Z -> Z) */

int foo252(int * arr, int arr_len, int n, int sum) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

        int count = 0;
       
  /*0*/ 
 /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= i && i <= n) &&
    (count >= 0) &&
    (count == count_pairs(arr, 0, i, sum))
    */
for (int i = 0; i < n; i++) {
           
  /*1*/ 
 /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (i + 1 <= j && j <= n) &&
    (count >= 0) &&
    (count == count_pairs(arr, 0, i, sum) + count_pairs(arr + i + 1, i + 1, j, sum))
    */
for (int j = i + 1; j < n; j++) {
                if (arr[i] + arr[j] == sum) {
                    count++;
                }
            }
        }
        return count;
}