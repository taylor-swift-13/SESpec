#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo7(int * arr, int arr_len, int key);

int foo7(int * arr, int arr_len, int key) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100
Ensure Results(__return)
*/{

        if (arr_len == 0) {
            return -1;
        } else {
            int low = 0;
            int high = arr_len;
            int mid =  high / 2;

           
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100 &&
    ((!(0 < arr_len@pre && arr@pre_l[arr_len@pre / 2] != key@pre)) => ((mid == arr_len@pre / 2)&&(high == arr_len@pre)&&(low == 0)&&(key == key@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre))) &&
(key == key@pre) &&
(arr_len == arr_len@pre) &&
(arr == arr@pre) &&
(forall (i:Z), 0 <= i && i < arr_len@pre => arr_l[i] == arr@pre_l[i]
          loop assigns low, high, mid)
    */
    
            while (low < high && arr[mid] != key) {
                if (arr[mid] < key) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
                mid = low + (high - low) / 2;
            }
            if (low >= high) {
                return -1;
            }
            return mid;
        }
}