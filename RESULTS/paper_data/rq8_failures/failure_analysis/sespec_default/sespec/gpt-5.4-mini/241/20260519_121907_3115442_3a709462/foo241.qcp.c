#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo241(int * arr, int arr_len, int n);

int foo241(int * arr, int arr_len, int n) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100
Ensure Results(__return)
*/{

        int count = 0;
        int length = arr_len;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100 &&
    ((i < arr_len@pre - 1) => (count >= 0)) &&
((!(i < arr_len@pre - 1)) => ((length == arr_len@pre)&&(count == 0)&&(n == n@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre))) &&
(length == arr_len@pre) &&
(n == n@pre) &&
(arr_len == arr_len@pre) &&
(arr == arr@pre) &&
(forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre
          loop assigns i, count)
    */
    
            for (int i = 0; i < length - 1; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant i <= length;
              loop invariant 0 <= count;
              loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
              loop assigns i, count;
            */
            for (int j = i + 1; j < length; j++) {
                if (arr[i] != arr[j]) {
                    count++;
                }
            }
            
        }
        return count;
}