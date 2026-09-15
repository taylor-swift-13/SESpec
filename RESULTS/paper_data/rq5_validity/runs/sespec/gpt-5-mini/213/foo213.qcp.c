#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo213(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int rotations, int index) 
/*@
With arr_l ranges_l
Require store_int_array(arr, arr_len, arr_l) && store_int_array(ranges, ranges_rows * ranges_cols, ranges_l)
Ensure Results(__return)
*/{

       
  /*@ Inv
    exists  arr_l ranges_l,    
    store_int_array(arr, arr_len, arr_l) && store_int_array(ranges, ranges_rows * ranges_cols, ranges_l) &&
    (-1 <= i && i < rotations) &&
    (0 <= arr_len) &&
    (0 <= rotations) &&
    (forall (k:Z), 0 <= k && k < rotations => true)) &&
    (arr == arr@pre) &&
    (arr_len == arr_len@pre) &&
    (ranges == ranges@pre) &&
    (ranges_len == ranges_len@pre) &&
    (ranges_rows == ranges_rows@pre) &&
    (ranges_cols == ranges_cols@pre) &&
    (rotations == rotations@pre) &&
    ((i >= 0) => (0 <= index && index < arr_len)) &&
    (forall (k:Z), 0 <= k && k < ranges_len => (0 <= ranges_l[k]@pre[0] && ranges_l[k]@pre[0] <= ranges_l[k]@pre[1] && ranges_l[k]@pre[1] < arr_len)) &&
    ((!(i >= 0)) => (0 <= index && index < arr_len))
    */
for (int i = rotations - 1; i >= 0; i--) {
        int left = ranges[i][0];
        int right = ranges[i][1];
        if (left <= index && right >= index) {
            if (index == left) {
                index = right;
            } else {
                index = index - 1;
            }
        }
    }
        return arr[index];
}