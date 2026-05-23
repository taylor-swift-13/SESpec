#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo177(int * arr, int arr_len, int array) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

		int i = 0;
		int hi = arr_len - 1;
		int end = 0;
	
 	/*0*/ 
 /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= i) &&
    (hi < arr_len) &&
    (i <= hi + 1)
    */
while (i <= hi) {
			end = (i + hi) / 2;
			if (arr[end] == array) {
				if (end == arr_len - 1
						|| arr[end + 1] != array) {
					return end;
				} else {
					i = end + 1;
				}
			} else if (arr[end] < array) {
				i = end + 1;
			} else {
				hi = end - 1;
			}
		}
		return -1;
}