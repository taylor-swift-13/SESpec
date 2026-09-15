#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (ranges_ok : Z -> Z -> Z -> Prop) */
int foo208(int * arr, int arr_len, int * * ranges, int ranges_len, int ranges_rows, int ranges_cols, int num, int count) 
/*@
With arr_l ranges_l
Require store_int_array(arr, arr_len, arr_l) && store_int_array(ranges, ranges_rows * ranges_cols, ranges_l)
Ensure Results(__return)
*/{

	
 	/*@ Inv
    exists  arr_l ranges_l,    
    store_int_array(arr, arr_len, arr_l) && store_int_array(ranges, ranges_rows * ranges_cols, ranges_l) &&
    (-1 <= r && r < num) &&
    (0 <= count && count < arr_len)
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