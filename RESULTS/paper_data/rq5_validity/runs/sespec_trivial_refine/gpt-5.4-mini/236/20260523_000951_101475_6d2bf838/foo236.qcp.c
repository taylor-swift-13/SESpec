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

       
  /*0*/ 
 /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= i && i <= n) &&
    (-1 <= j && j < n) &&
    (i <= j + 1) &&
    (result == -1 || (0 <= result && result < n && arr_l[result] == x)) &&
    (result == -1 || result < i) &&
    (forall (k:Z), 0 <= k && k < i => arr_l[k] <= x) &&
    (forall (k:Z), j < k && k < n => arr_l[k] >= x)
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