#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_eq : Z -> Z -> Z -> Z -> Z) */
int foo91(int * arr, int arr_len, int key) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

        if (arr_len == 0) {
            return -1;
        } else {
            int low = 0;
            int high = arr_len;
            int mid =  high / 2;

           
  /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (key == key@pre) &&
    (arr_len == arr_len@pre) &&
    (arr == arr@pre) &&
    (forall (k:Z), 0 <= k && k < arr_len@pre => arr_l[k] == arr_l[k]@pre) &&
    ((low < high) => (mid == low + (high - low) / 2)) &&
    (forall (k:Z), 0 <= k && k < arr_len@pre => arr_l[k] == arr_l[k]@pre) &&
    ((high - low == 0) => (low >= high)) &&
    ((0 < arr_len@pre && arr@pre[arr_len@pre / 2] != key@pre) => (((mid == arr_len@pre / 2)&&(high == arr_len@pre)&&(low == 0)&&(key == key@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre)) || (low >= 0 && low <= arr_len@pre))) &&
    ((0 < arr_len@pre && arr@pre[arr_len@pre / 2] != key@pre) => (((mid == arr_len@pre / 2)&&(high == arr_len@pre)&&(low == 0)&&(key == key@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre)) || (high >= 0 && high <= arr_len@pre))) &&
    ((!(0 < arr_len@pre && arr@pre[arr_len@pre / 2] != key@pre)) => ((mid == arr_len@pre / 2)&&(high == arr_len@pre)&&(low == 0)&&(key == key@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre))) &&
    (key == key@pre) &&
    (arr_len == arr_len@pre) &&
    (arr == arr@pre) &&
    (forall (k:Z), 0 <= k && k < arr_len@pre => arr_l[k] == arr_l[k]@pre)
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