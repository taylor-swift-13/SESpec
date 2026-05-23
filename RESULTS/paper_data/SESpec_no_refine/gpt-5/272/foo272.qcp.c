#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

const char * foo272(int * arr, int arr_len, int n);

const char * foo272(int * arr, int arr_len, int n) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100
Ensure Results(__return)
*/{

        if (n == 0) {
            return "NO";
        }

        int firstElement = arr[0];
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100 &&
    (forall (k:Z), 1 <= k && k < i => arr_l[k] == firstElement) &&
((!(i < n)) => \true) &&
(forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre
          loop assigns i)
    */
    
            for (int i = 1; i < n; i++) {
            if (arr[i] != firstElement) {
                return "NO";
            }
        }
        return "YES";
}