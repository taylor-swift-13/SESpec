#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (odd_with_index : Z -> Z -> Z -> Z -> Z) */
/*@ Extern Coq (paircount_prefix : Z -> Z -> Z -> Z) */
int foo222(int * arr, int arr_len, int n) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

		int result = 0;
		int offset = arr_len;
	
 	/*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= index && index <= offset) &&
    (result >= 0) &&
    (result == paircount_prefix(arr, index, offset)) &&
    (forall (k:Z), 0 <= k && k < offset => arr_l[k] == arr_l[k]@pre) &&
    (forall (k:Z), 0 <= k && k < offset => 0 <= arr_l[k] && arr_l[k] <= 100) &&
    (index <= offset) &&
    (offset == arr_len@pre) &&
    (n == n@pre) &&
    (arr_len == arr_len@pre) &&
    (arr == arr@pre)
    */
for (int index = 0; index < offset; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant c >= index + 1 && c <= offset;
          loop invariant result >= 0;
          loop invariant result == paircount_prefix(arr, index, offset) + odd_with_index(arr, index, index + 1, c);
          loop invariant \forall integer k; 0 <= k < offset ==> arr[k] == \at(arr[k],Pre);
          loop assigns c, result;
            */
            /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (c >= index + 1 && c <= offset) &&
    (result >= 0) &&
    (result == paircount_prefix(arr, index, offset) + odd_with_index(arr, index, index + 1, c)) &&
    (forall (k:Z), 0 <= k && k < offset => arr_l[k] == arr_l[k]@pre)
    */
for (int c = index + 1; c < offset; c++) {
				if ((arr[index] ^ arr[c]) % 2 == 1) {
					result++;
				}
			}
            
		}
		return result;
}