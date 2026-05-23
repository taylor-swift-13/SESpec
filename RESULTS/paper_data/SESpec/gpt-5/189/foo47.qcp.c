#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo47(int n, int * arr, int arr_len);

int foo47(int n, int * arr, int arr_len) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100
Ensure Results(__return)
*/{

        if (n == 0) {
            return 0;
        }

        int min = arr[0];
        int count = 1;

       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100 &&
    (1 <= i) &&
((i < n) => i <= n) &&
(arr_len@pre == arr_len) &&
(arr@pre == arr) &&
(n@pre == n) &&
(forall (k:Z), 0 <= k && k < arr_len@pre => arr_l[k] == arr_l[k]@pre) &&
(1 <= count && count <= i
          loop assigns i, min, count)
    */
    
        for (int i = 1; i < n; i++) {
            if (min > arr[i]) {
                min = arr[i];
                count = 1;
            } else if (min == arr[i]) {
                count++;
            }
        }
        return count;
}