#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (Unchanged_int_array : Z -> Z -> Z -> Prop) */
int foo172(int * arr1, int arr1_len, int * arr, int arr_len, int Array, int n, int p) 
/*@
With arr1_l arr_l
Require store_int_array(arr1, arr1_len, arr1_l) && store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

		int result = 0;
		int s = 0;

	
 	/*@ Inv
    exists  arr1_l arr_l,    
    store_int_array(arr1, arr1_len, arr1_l) && store_int_array(arr, arr_len, arr_l) &&
    (0 <= count && count <= p) &&
    (0 <= result + s <= count) &&
    (forall (i:Z), 0 <= i && i < result => arr1_l[i] == arr1_l[i]@pre) &&
    (forall (j:Z), 0 <= j && j < s => arr_l[j] == arr_l[j]@pre) &&
    ((count < p@pre) => (result < arr1_len || s < arr_len)) &&
    ((!(count < p@pre)) => ((s == 0)&&(result == 0)&&(p == p@pre)&&(n == n@pre)&&(Array == Array@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre)&&(arr1_len == arr1_len@pre)&&(arr1 == arr1@pre))) &&
    (p == p@pre) &&
    (n == n@pre) &&
    (Array == Array@pre) &&
    (arr_len == arr_len@pre) &&
    (arr == arr@pre) &&
    (arr1_len == arr1_len@pre) &&
    (arr1 == arr1@pre) &&
    (Unchanged_int_array(arr1, arr1_len, arr1@pre)) &&
    (Unchanged_int_array(arr, arr_len, arr@pre))
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