#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo22(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int c);

int foo22(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int c) 
/*@
With arr1_l arr_l
Require store_int_array(arr1, arr1_len, arr1_l) && arr1_len > 0 && arr1_len < 100 && store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100
Ensure Results(__return)
*/{

		int result = 0;
		int tmp = 0;

	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  arr1_l arr_l,    
    store_int_array(arr1, arr1_len, arr1_l) && arr1_len > 0 && arr1_len < 100 && store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100 &&
    (0 <= count) &&
((count < c@pre) => (0 <= result && 0 <= tmp && result + tmp == count)) &&
((!(count < c@pre)) => ((tmp == 0)&&(result == 0)&&(c == c@pre)&&(n == n@pre)&&(Array == Array@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre)&&(arr1_len == arr1_len@pre)&&(arr1 == arr1@pre))) &&
(c == c@pre) &&
(n == n@pre) &&
(Array == Array@pre) &&
(arr_len == arr_len@pre) &&
(arr == arr@pre) &&
(arr1_len == arr1_len@pre) &&
(arr1 == arr1@pre) &&
(forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre ) &&
(forall (k:Z), 0 <= k && k < arr1_len => arr1_l[k] == arr1_l[k]@pre 
          loop assigns count, result, tmp)
    */
    
            for (int count = 0; count < c; count++) {
			if (result < Array
					&& (tmp >= n || arr1[result] <= arr[tmp])) {
				if (count == c - 1) {
					return arr1[result];
				}
				result++;
			} else {
				if (count == c - 1) {
					return arr[tmp];
				}
				tmp++;
			}
		}
		return -1;
}