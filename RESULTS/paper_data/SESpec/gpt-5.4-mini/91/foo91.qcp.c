#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
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
    (0 <= low) &&
    (arr_len < 0 || (low <= high && high <= arr_len)) &&
    (arr_len < 0 || (0 <= mid && mid <= arr_len)) &&
    (key == key@pre) &&
    (arr_len == arr_len@pre) &&
    (arr == arr@pre) &&
    (forall (i:Z), 0 <= i && i < arr_len => arr_l[i] == arr_l[i]@pre) &&
    (mid == low + (high - low) / 2) &&
    (low <= high || arr_len < 0) &&
    (arr_len < 0 || high - low >= 0 || low == high) &&
    ((low < high) => (low <= mid && mid < high)) &&
    ((0 < arr_len@pre && arr@pre[arr_len@pre / 2] != key@pre) => (0 <= mid && mid <= arr_len@pre)) &&
    ((0 < arr_len@pre && arr@pre[arr_len@pre / 2] != key@pre) => (((mid == arr_len@pre / 2)&&(high == arr_len@pre)&&(low == 0)&&(key == key@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre)) || (0 <= low && low <= high))) &&
    ((0 < arr_len@pre && arr@pre[arr_len@pre / 2] != key@pre) => (((mid == arr_len@pre / 2)&&(high == arr_len@pre)&&(low == 0)&&(key == key@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre)) || (arr_len < 0 || (low <= high && high <= arr_len)))) &&
    ((0 < arr_len@pre && arr@pre[arr_len@pre / 2] != key@pre) => (((mid == arr_len@pre / 2)&&(high == arr_len@pre)&&(low == 0)&&(key == key@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre)) || (arr_len < 0 || (0 <= mid && mid <= arr_len)))) &&
    ((!(0 < arr_len@pre && arr@pre[arr_len@pre / 2] != key@pre)) => ((mid == arr_len@pre / 2)&&(high == arr_len@pre)&&(low == 0)&&(key == key@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre))) &&
    (forall (i:Z), 0 <= i && i < arr_len => arr_l[i] == arr_l[i]@pre)
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