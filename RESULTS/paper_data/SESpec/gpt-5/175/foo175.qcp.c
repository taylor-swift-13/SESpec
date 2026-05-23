#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo175(int * arr, int arr_len, int Array) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

		int i = 0;
		int hi = arr_len - 1;
		int end = 0;
	
 	/*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= i && i <= arr_len) &&
    (-1 <= hi && hi <= arr_len - 1) &&
    (i <= hi + 1) &&
    (forall (k:Z), 0 <= k + 1 < arr_len => arr_l[k] <= arr_l[k+1]) &&
    (forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre) &&
    ((i > hi) => (i == hi + 1)) &&
    (Array == Array@pre) &&
    (arr_len == arr_len@pre) &&
    (arr == arr@pre)
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