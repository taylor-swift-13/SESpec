#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (range_count : Z -> Z -> Z -> Z -> Z) */

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
    (-1 <= r && r < num) &&
    (0 <= r + 1 <= num) &&
    (count == range_count(ranges, r + 1, num, count@pre)) &&
    (forall (k:Z), 0 <= k && k < ranges_len => true)) &&
    (ranges_cols == ranges_cols@pre) &&
    (ranges_rows == ranges_rows@pre) &&
    (ranges_len == ranges_len@pre) &&
    (ranges == ranges@pre) &&
    (arr_len == arr_len@pre) &&
    (arr == arr@pre) &&
    (num == num@pre) &&
    (forall (k:Z), 0 <= k && k < ranges_len => forall (j:Z), 0 <= j && j < ranges_cols => ranges_l[k][j] == ranges_l[k][j]@pre)
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