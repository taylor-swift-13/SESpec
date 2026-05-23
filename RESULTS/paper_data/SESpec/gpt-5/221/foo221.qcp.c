#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (cnt_odd_xor_pairs : Z -> Z -> Z -> Z -> Z -> Z) */
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
    (offset == arr_len@pre) &&
    (n == n@pre) &&
    (arr_len == arr_len@pre) &&
    (arr == arr@pre) &&
    (forall (k:Z), 0 <= k && k < offset => 0 <= arr_l[k] && arr_l[k] <= 100) &&
    (forall (k:Z), 0 <= k && k < offset => arr_l[k] == arr_l[k]@pre) &&
    (found >= 0) &&
    ((c < arr_len@pre) => (forall (k:Z), 0 <= k && k < offset => arr_l[k] == arr_l[k]@pre))
    */
for (int c = 0; c < offset; c++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant found >= 0;
          loop assigns c, found;
            */
            /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
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