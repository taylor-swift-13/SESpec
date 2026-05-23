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

	
 	/*@ Inv
    exists  arr1_l arr_l,    
    store_int_array(arr1, arr1_len, arr1_l) && store_int_array(arr, arr_len, arr_l) &&
    (0 <= count && count <= p) &&
    (0 <= result && result <= Array) &&
    (0 <= tmp) &&
    (result + tmp == count) &&
    (tmp <= count) &&
    ((count < p) => (result <= Array)) &&
    ((count < p) => (tmp <= n)) &&
    ((count < p@pre) => (result <= Array@pre && tmp <= n@pre)) &&
    ((count < p@pre) => (result + tmp == count)) &&
    ((count < p@pre) => (0 <= result && 0 <= tmp)) &&
    ((count < p@pre) => (arr1_len == arr1_len@pre && arr_len == arr_len@pre)) &&
    ((count < p@pre) => (arr1 == arr1@pre && arr == arr@pre)) &&
    ((count < p@pre) => (n == n@pre && p == p@pre && Array == Array@pre)) &&
    ((count < p@pre) => (result <= count && tmp <= count)) &&
    ((count < p@pre) => (result == 0 || tmp == 0 || result + tmp > 0)) &&
    ((count < p@pre) => (result < Array || tmp < n || result + tmp == count)) &&
    ((!(count < p@pre)) => ((tmp == 0)&&(result == 0)&&(p == p@pre)&&(n == n@pre)&&(Array == Array@pre)&&(arr_len == arr_len@pre)&&(arr == arr@pre)&&(arr1_len == arr1_len@pre)&&(arr1 == arr1@pre))) &&
    (p == p@pre) &&
    (n == n@pre) &&
    (Array == Array@pre) &&
    (arr_len == arr_len@pre) &&
    (arr == arr@pre) &&
    (arr1_len == arr1_len@pre) &&
    (arr1 == arr1@pre) &&
    (arr == arr@pre) &&
    (arr1 == arr1@pre) &&
    (forall (i:Z), 0 <= i && i < arr_len => arr_l[i] == arr_l[i]@pre) &&
    (forall (i:Z), 0 <= i && i < arr1_len => arr1_l[i] == arr1_l[i]@pre)
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