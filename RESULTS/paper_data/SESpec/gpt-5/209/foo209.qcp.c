#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo209(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int width) 
/*@
With arr_l ranges_l
Require store_int_array(arr, arr_len, arr_l) && store_int_array(ranges, ranges_rows * ranges_cols, ranges_l)
Ensure Results(__return)
*/{

	
 	/*@ Inv
    exists  arr_l ranges_l,    
    store_int_array(arr, arr_len, arr_l) && store_int_array(ranges, ranges_rows * ranges_cols, ranges_l) &&
    (array == array@pre) &&
    (ranges == ranges@pre) &&
    (arr == arr@pre) &&
    (ranges_len == ranges_len@pre) &&
    (ranges_rows == ranges_rows@pre) &&
    (ranges_cols == ranges_cols@pre) &&
    (arr_len == arr_len@pre) &&
    ((r >= 0) => (0 <= r && r < array)) &&
    ((r == array - 1) => (width == width@pre))
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