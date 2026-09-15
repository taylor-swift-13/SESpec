#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo241(int * arr, int arr_len, int n) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

        int count = 0;
        int length = arr_len;
       
  /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= count) &&
    (length == arr_len) &&
    (n == n@pre) &&
    (arr_len == arr_len@pre) &&
    (arr == arr@pre) &&
    (forall (k:Z), 0 <= k && k < length => arr_l[k] == arr_l[k]@pre) &&
    (forall (k:Z), 0 <= k && k < length => 0 <= arr_l[k] && arr_l[k] <= 100)
    */
for (int i = 0; i < length - 1; i++) {
        
            /*@
              loop invariant i + 1 <= j <= length;
              loop invariant 0 <= count;
              loop invariant \forall integer k; 0 <= k < length ==> arr[k] == \at(arr[k], Pre);
              loop invariant \forall integer k; 0 <= k < length ==> 0 <= arr[k] <= 100;
              loop assigns j, count;
            */
            /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (i + 1 <= j && j <= length) &&
    (0 <= count) &&
    (forall (k:Z), 0 <= k && k < length => arr_l[k] == arr_l[k]@pre) &&
    (forall (k:Z), 0 <= k && k < length => 0 <= arr_l[k] && arr_l[k] <= 100)
    */
for (int j = i + 1; j < length; j++) {
                if (arr[i] != arr[j]) {
                    count++;
                }
            }
            
        }
        return count;
}