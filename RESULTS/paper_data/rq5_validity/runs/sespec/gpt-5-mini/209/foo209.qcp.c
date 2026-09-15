#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (apply_ranges : Z -> Z -> Z -> Z -> Z) */

int foo209(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int width) 
/*@
With arr_l ranges_l
Require store_int_array(arr, arr_len, arr_l) && store_int_array(ranges, ranges_rows * ranges_cols, ranges_l)
Ensure Results(__return)
*/{

	
 	/*0*/ 
 /*@ Inv
    exists  arr_l ranges_l,    
    store_int_array(arr, arr_len, arr_l) && store_int_array(ranges, ranges_rows * ranges_cols, ranges_l) &&
    (-1 <= r && r < array) &&
    (0 <= width && width < arr_len) &&
    (0 <= arr_len) &&
    (0 <= ranges_len) &&
    ((r >= 0) => true)) &&
    ((r >= 0) => (0 <= ranges_l[r][0] && 0 <= ranges_l[r][1])) &&
    (apply_ranges(ranges, r+1, array, width@pre) == width) &&
    ((r < 0) => (width == apply_ranges(ranges, 0, array, width@pre))) &&
    (forall (k:Z), r+1 <= k && k < array => (apply_ranges(ranges, k, array, width@pre) == apply_ranges(ranges, r+1, array, width@pre))) &&
    (array == array@pre) &&
    (ranges_cols == ranges_cols@pre) &&
    (ranges_rows == ranges_rows@pre) &&
    (ranges_len == ranges_len@pre) &&
    (ranges == ranges@pre) &&
    (arr_len == arr_len@pre) &&
    (arr == arr@pre) &&
    (forall (k:Z), 0 <= k && k < ranges_len => ranges_l[k][0] == ranges_l[k][0]@pre && ranges_l[k][1] == ranges_l[k][1]@pre)
    */
for (int r = array - 1; r >= 0; r--) {
			int j = ranges[r][0];
			int top = ranges[r][1];
			if (j <= width && top >= width) {
				if (width == j) {
					width = top;
				} else {
					width = width - 1;
				}
			}
		}
		return arr[width];
}