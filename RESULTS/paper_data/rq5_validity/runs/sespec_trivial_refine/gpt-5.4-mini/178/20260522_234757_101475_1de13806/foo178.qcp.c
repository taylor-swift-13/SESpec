#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo178(int * arr1, int arr1_len, int * arr2, int arr2_len, int m, int n, int k) 
/*@
With arr1_l arr2_l
Require store_int_array(arr1, arr1_len, arr1_l) && store_int_array(arr2, arr2_len, arr2_l)
Ensure Results(__return)
*/{

        int i = 0;
        int j = 0;

       
  /*@ Inv
    exists  arr1_l arr2_l,    
    store_int_array(arr1, arr1_len, arr1_l) && store_int_array(arr2, arr2_len, arr2_l) &&
    (0 <= count && count <= k) &&
    (0 <= i && i <= m) &&
    (0 <= j) &&
    (i + j == count)
    */
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