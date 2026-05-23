#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
const char * foo272(int * arr, int arr_len, int n) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

        if (n == 0) {
            return "NO";
        }

        int firstElement = arr[0];
       
  /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (1 <= i) &&
    (forall (k:Z), 1 <= k && k < i => arr_l[k] == firstElement)
    */
for (int i = 1; i < n; i++) {
            if (arr[i] != firstElement) {
                return "NO";
            }
        }
        return "YES";
}