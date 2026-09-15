#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo208(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int num, int count) 
/*@
With arr_l ranges_l
Require store_int_array(arr, arr_len, arr_l) && store_int_array(ranges, ranges_rows * ranges_cols, ranges_l)
Ensure Results(__return)
*/{

	
 	/*0*/ 
 /*@ Inv
    exists  arr_l ranges_l,    
    store_int_array(arr, arr_len, arr_l) && store_int_array(ranges, ranges_rows * ranges_cols, ranges_l) &&
    (-1 <= r && r <= num - 1) &&
    (0 <= num) &&
    ((r >= 0) => (0 <= r && r < num)) &&
    (arr == arr@pre) &&
    (arr_len == arr_len@pre) &&
    (ranges == ranges@pre) &&
    (ranges_len == ranges_len@pre) &&
    (ranges_rows == ranges_rows@pre) &&
    (ranges_cols == ranges_cols@pre) &&
    (num == num@pre) &&
    (forall (k:Z), 0 <= k && k < ranges_len => ranges_l[k] == ranges_l[k]@pre) &&
    ((r >= 0) => (j == ranges_l[r][0])) &&
    ((r >= 0) => (top == ranges_l[r][1])) &&
    ((r < 0) => (0 <= count && count < arr_len))
    */
for (int r = num - 1; r >= 0; r--) {
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