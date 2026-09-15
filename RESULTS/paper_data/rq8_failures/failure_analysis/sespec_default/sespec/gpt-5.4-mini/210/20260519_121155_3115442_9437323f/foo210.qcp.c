#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo210(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int count);

int foo210(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int array, int count) 
/*@
With arr_l ranges_l
Require store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100 && store_int_array(ranges, ranges_len, ranges_l) && ranges_len > 0 && ranges_len < 100
Ensure Results(__return)
*/{

	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  arr_l ranges_l,    
    store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100 && store_int_array(ranges, ranges_len, ranges_l) && ranges_len > 0 && ranges_len < 100 &&
    (array == array@pre) &&
(ranges_cols == ranges_cols@pre) &&
(ranges_rows == ranges_rows@pre) &&
(ranges_len == ranges_len@pre) &&
(ranges == ranges@pre) &&
(arr_len == arr_len@pre) &&
(arr == arr@pre)
    */
    
            for (int r = array - 1; r >= 0; r--) {
			int j = ranges[r][0];
			int top = ranges[r][1];
			if (j <= count && top >= count) {
				if (count == j) {
					count = top;
				} else {
					count = count - 1;
				}
			}
		}
		return arr[count];
}