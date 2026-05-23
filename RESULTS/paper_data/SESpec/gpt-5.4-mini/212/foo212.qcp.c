#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo212(int * arr1, int arr1_len, int * arr2, int arr2_len, int n) 
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
    (0 <= i && 0 <= j) &&
    (i == 0 || j == 0 || i + j > 0) &&
    (forall (k:Z), 0 <= k && k < arr1_len => arr1_l[k] == arr1_l[k]@pre) &&
    (forall (k:Z), 0 <= k && k < arr2_len => arr2_l[k] == arr2_l[k]@pre) &&
    ((0 < arr1_len@pre && 0 < arr2_len@pre) => (i <= arr1_len && j <= arr2_len)) &&
    ((0 < arr1_len@pre && 0 < arr2_len@pre) => (0 <= i && i <= arr1_len)) &&
    ((0 < arr1_len@pre && 0 < arr2_len@pre) => (0 <= j && j <= arr2_len)) &&
    ((0 < arr1_len@pre && 0 < arr2_len@pre) => (i + j <= arr1_len + arr2_len)) &&
    ((0 < arr1_len@pre && 0 < arr2_len@pre) => (i < arr1_len && j < arr2_len => i + 1 <= arr1_len && j + 1 <= arr2_len)) &&
    ((0 < arr1_len@pre && 0 < arr2_len@pre) => (0 <= i && i <= arr1_len)) &&
    ((0 < arr1_len@pre && 0 < arr2_len@pre) => (0 <= j && j <= arr2_len)) &&
    ((!(0 < arr1_len@pre && 0 < arr2_len@pre)) => ((j == 0)&&(i == 0)&&(n == n@pre)&&(arr2_len == arr2_len@pre)&&(arr2 == arr2@pre)&&(arr1_len == arr1_len@pre)&&(arr1 == arr1@pre))) &&
    (n == n@pre) &&
    (arr2_len == arr2_len@pre) &&
    (arr2 == arr2@pre) &&
    (arr1_len == arr1_len@pre) &&
    (arr1 == arr1@pre) &&
    (forall (k:Z), 0 <= k && k < arr1_len => arr1_l[k] == arr1_l[k]@pre) &&
    (forall (k:Z), 0 <= k && k < arr2_len => arr2_l[k] == arr2_l[k]@pre)
    */
while (i < arr1_len && j < arr2_len) {
            if (arr1[i] < arr2[j]) {
                i++;
            } else if (arr1[i] > arr2[j]) {
                j++;
            } else {
                i++;
                j++;
            }
        }
        return i < arr1_len ? i : j;
}