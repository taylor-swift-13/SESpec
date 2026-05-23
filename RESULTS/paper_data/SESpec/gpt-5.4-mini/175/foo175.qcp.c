#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo175(int * arr, int arr_len, int Array);

int foo175(int * arr, int arr_len, int Array) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100
Ensure Results(__return)
*/{

		int i = 0;
		int hi = arr_len - 1;
		int end = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100 &&
    ((0 <= arr_len@pre - 1) => (0 <= i && i <= arr_len@pre && -1 <= hi && hi < arr_len@pre && 0 <= end && end < arr_len@pre)) &&
((0 <= arr_len@pre - 1) => (((end == 0)&&(hi == arr_len@pre - 1)&&(i == 0)&&(Array == Array@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre)) || (i == 0 || hi == arr_len@pre - 1 || end >= 0))) &&
((0 <= arr_len@pre - 1) => (((end == 0)&&(hi == arr_len@pre - 1)&&(i == 0)&&(Array == Array@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre)) || (hi == arr_len@pre - 1 || i <= hi + 1))) &&
((0 <= arr_len@pre - 1) => (((end == 0)&&(hi == arr_len@pre - 1)&&(i == 0)&&(Array == Array@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre)) || (end >= 0 || i == 0))) &&
((!(0 <= arr_len@pre - 1)) => ((end == 0)&&(hi == arr_len@pre - 1)&&(i == 0)&&(Array == Array@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre))) &&
(Array == Array@pre) &&
(arr_len == arr_len@pre) &&
(arr == arr@pre) &&
(forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre
          loop assigns end, i, hi)
    */
    
            while (i <= hi) {
			end = (i + hi) / 2;
			if (arr[end] == Array) {
				if (end == arr_len - 1
						|| arr[end + 1] != Array) {
					return end;
				} else {
					i = end + 1;
				}
			} else if (arr[end] < Array) {
				i = end + 1;
			} else {
				hi = end - 1;
			}
		}
		return -1;
}