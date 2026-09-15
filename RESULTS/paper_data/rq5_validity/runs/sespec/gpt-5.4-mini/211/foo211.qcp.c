#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (abs : Z -> Z) */
int foo211(int * arr, int arr_len, int n) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

        int count = 0;
        int i = 0;
        int j = 1;

       
  /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= i && i <= n) &&
    (1 <= j && j <= n) &&
    (0 <= count && count <= i) &&
    (count <= j - 1) &&
    (i <= j) &&
    (n == n@pre) &&
    (arr_len == arr_len@pre) &&
    (arr == arr@pre) &&
    (forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre) &&
    (forall (k:Z), 0 <= k && k < i => k < n) &&
    (forall (k:Z), 1 <= k && k < j => k < n) &&
    ((0 < n@pre && 1 < n@pre) => (count <= i && count <= j - 1)) &&
    ((0 < n@pre && 1 < n@pre) => (0 <= i && i <= n@pre)) &&
    ((0 < n@pre && 1 < n@pre) => (1 <= j && j <= n@pre)) &&
    ((!(0 < n@pre && 1 < n@pre)) => ((j == 1)&&(i == 0)&&(count == 0)&&(n == n@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre))) &&
    (n == n@pre) &&
    (arr_len == arr_len@pre) &&
    (arr == arr@pre) &&
    (forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre)
    */
while (i < n && j < n) {
            if (arr[i] == arr[j]) {
                i++;
                j++;
                count++;
            } else if (arr[i] > arr[j]) {
                i++;
            } else {
                j++;
            }
        }

        return count;
}