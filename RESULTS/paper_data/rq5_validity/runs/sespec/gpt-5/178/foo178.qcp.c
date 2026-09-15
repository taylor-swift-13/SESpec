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
    (i >= 0) &&
    (j >= 0) &&
    ((m >= 0) => (i <= m)) &&
    (i + j == count) &&
    (forall (t:Z), 0 <= t && t < i => 0 <= t) &&
    (forall (t:Z), 0 <= t && t < j => 0 <= t) &&
    ((i < m && j < n) => (arr1_l[i] <= arr2_l[j] || arr2_l[j] < arr1_l[i])) &&
    (count >= 0) &&
    ((k@pre >= 0) => (count <= k@pre)) &&
    (forall (t:Z), 0 <= t && t < arr1_len => arr1_l[t] == arr1_l[t]@pre) &&
    (forall (t:Z), 0 <= t && t < arr2_len => arr2_l[t] == arr2_l[t]@pre) &&
    ((count < k@pre) => (i >= 0)) &&
    ((count < k@pre) => (j >= 0)) &&
    ((!(count < k@pre)) => ((j == 0)&&(i == 0)&&(k == k@pre)&&(n == n@pre)&&(m == m@pre)&&(arr2_len == arr2_len@pre)&&(arr2 == arr2@pre)&&(arr1_len == arr1_len@pre)&&(arr1 == arr1@pre))) &&
    (k == k@pre) &&
    (n == n@pre) &&
    (m == m@pre) &&
    (arr2_len == arr2_len@pre) &&
    (arr2 == arr2@pre) &&
    (arr1_len == arr1_len@pre) &&
    (arr1 == arr1@pre)
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