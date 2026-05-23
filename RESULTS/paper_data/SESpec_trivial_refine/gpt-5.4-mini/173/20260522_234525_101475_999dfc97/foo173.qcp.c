#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo173(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int p) 
/*@
With arr1_l arr_l
Require store_int_array(arr1, arr1_len, arr1_l) && store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

		int result = 0;
		int tmp = 0;

	
 	/*0*/ 
 /*@ Inv
    exists  arr1_l arr_l,    
    store_int_array(arr1, arr1_len, arr1_l) && store_int_array(arr, arr_len, arr_l) &&
    (count >= 0) &&
    ((p < 0) || count <= p) &&
    (result >= 0) &&
    (tmp >= 0) &&
    (result + tmp == count)
    */
for (int count = 0; count < p; count++) {
			if (result < Array
					&& (tmp >= n || arr1[result] <= arr[tmp])) {
				if (count == p - 1) {
					return arr1[result];
				}
				result++;
			} else {
				if (count == p - 1) {
					return arr[tmp];
				}
				tmp++;
			}
		}
		return -1;
}