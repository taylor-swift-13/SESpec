#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo72(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int rotations, int index);

int foo72(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int rotations, int index) 
/*@
With arr_l ranges_l
Require store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100 && store_int_array(ranges, ranges_len, ranges_l) && ranges_len > 0 && ranges_len < 100
Ensure Results(__return)
*/{

       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  arr_l ranges_l,    
    store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100 && store_int_array(ranges, ranges_len, ranges_l) && ranges_len > 0 && ranges_len < 100 &&
    (rotations == rotations@pre) &&
(ranges_cols == ranges_cols@pre) &&
(ranges_rows == ranges_rows@pre) &&
(ranges_len == ranges_len@pre) &&
(ranges == ranges@pre) &&
(arr_len == arr_len@pre) &&
(arr == arr@pre) &&
(i <= rotations - 1) &&
((i >= 0) => (0 <= i && i < rotations)

      loop assigns i, index)
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