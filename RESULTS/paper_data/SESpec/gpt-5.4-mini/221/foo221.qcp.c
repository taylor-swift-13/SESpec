#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (parity : Z -> Z) */
/*@ Extern Coq (cnt_odd_with : Z -> Z -> Z -> Z) */
/*@ Extern Coq (pair_count : Z -> Z -> Z) */
int foo221(int * arr, int arr_len, int n) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

		int found = 0;
		int offset = arr_len;
	
 	/*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= c && c <= offset) &&
    (offset == arr_len) &&
    (n == n@pre) &&
    (arr_len == arr_len@pre) &&
    (arr == arr@pre) &&
    (found >= 0) &&
    ((c == offset) => found >= 0) &&
    (forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre)
    */
for (int c = 0; c < offset; c++) {
			
            /*@ 
              loop assigns index, found;
              loop invariant 0 <= c < offset;
              loop invariant c + 1 <= index <= offset;
              loop invariant found >= 0;
            */
            /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= c && c < offset) &&
    (c + 1 <= index && index <= offset) &&
    (found >= 0)
    */
for (int index = c + 1; index < offset; index++) {
				if ((arr[c] ^ arr[index]) % 2 == 1) {
					found++;
				}
			}
            
		}
		return found;
}