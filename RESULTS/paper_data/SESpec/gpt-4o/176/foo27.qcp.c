#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo27(int * arr, int arr_len, int array);

int foo27(int * arr, int arr_len, int array) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100
Ensure Results(__return)
*/{

		int found = 0;
		int hi = arr_len - 1;
		int end = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100 &&
    (0 <= found && found <= hi + 1 <= arr_len) &&
(0 <= end && end < arr_len) &&
(forall (i:Z), 0 <= i && i < arr_len => arr_l[i] == arr_l[i]@pre) &&
(count_eq(arr, 0, arr_len, array) == \at(count_eq(arr, 0, arr_len, array), Pre)) &&
(count_less(arr, 0, arr_len, array) == \at(count_less(arr, 0, arr_len, array), Pre)) &&
(count_greater(arr, 0, arr_len, array) == \at(count_greater(arr, 0, arr_len, array), Pre)
      loop assigns end, found, hi)
    */
    
    while (found <= hi) {
        end = (found + hi) / 2;
        if (arr[end] == array) {
            if (end == arr_len - 1
                    || arr[end + 1] != array) {
                return end;
            } else {
                found = end + 1;
            }
        } else if (arr[end] < array) {
            found = end + 1;
        } else {
            hi = end - 1;
        }
    }
		return -1;
}