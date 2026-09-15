#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo236(int * arr, int arr_len, int x, int n) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

        int i = 0;
        int j = n - 1;
        int result = -1;

       
  /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= i) &&
    (j < n@pre) &&
    ((n < 0) || (i <= j + 1)) &&
    (n == n@pre) &&
    (x == x@pre) &&
    (arr_len == arr_len@pre) &&
    (arr == arr@pre) &&
    (forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre) &&
    (forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre) &&
    ((0 <= n@pre - 1) => ((result == -1) || (0 <= result && result < n@pre && arr_l[result] == x))) &&
    ((0 <= n@pre - 1) => (((result == -1)&&(j == n@pre - 1)&&(i == 0)&&(n == n@pre)&&(x == x@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre)) || (0 <= i && i <= n@pre))) &&
    ((0 <= n@pre - 1) => (((result == -1)&&(j == n@pre - 1)&&(i == 0)&&(n == n@pre)&&(x == x@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre)) || (-1 <= j && j < n@pre))) &&
    ((0 <= n@pre - 1) => (((result == -1)&&(j == n@pre - 1)&&(i == 0)&&(n == n@pre)&&(x == x@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre)) || (result == -1 || (0 <= result && result < n@pre && arr_l[result] == x)))) &&
    ((!(0 <= n@pre - 1)) => ((result == -1)&&(j == n@pre - 1)&&(i == 0)&&(n == n@pre)&&(x == x@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre)))
    */
while (i <= j) {
            int mid = (i + j) / 2;
            if (arr[mid] == x) {
                result = mid;
                i = mid + 1;
            } else if (arr[mid] < x) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }

        return result;
}