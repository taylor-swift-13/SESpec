#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo23(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int p);

int foo23(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int p) 
/*@
With arr1_l arr_l
Require store_int_array(arr1, arr1_len, arr1_l) && arr1_len > 0 && arr1_len < 100 && store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100
Ensure Results(__return)
*/{

		int result = 0;
		int s = 0;

	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  arr1_l arr_l,    
    store_int_array(arr1, arr1_len, arr1_l) && arr1_len > 0 && arr1_len < 100 && store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100 &&
    ((!(count < p@pre)) => ((s == 0)&&(result == 0)&&(p == p@pre)&&(n == n@pre)&&(Array == Array@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre)&&(arr1_len == arr1_len@pre)&&(arr1 == arr1@pre))) &&
(p == p@pre) &&
(n == n@pre) &&
(Array == Array@pre) &&
(arr_len == arr_len@pre) &&
(arr == arr@pre) &&
(arr1_len == arr1_len@pre) &&
(arr1 == arr1@pre) &&
(forall (i:Z), 0 <= i && i < arr1_len => arr1_l[i] == arr1_l[i]@pre) &&
(forall (i:Z), 0 <= i && i < arr_len => arr_l[i] == arr_l[i]@pre
          loop assigns count, result, s)
    */
    
            for (int count = 0; count < p; count++) {
			if (result < Array
					&& (s >= n || arr1[result] <= arr[s])) {
				if (count == p - 1) {
					return arr1[result];
				}
				result++;
			} else {
				if (count == p - 1) {
					return arr[s];
				}
				s++;
			}
		}
		return -1;
}