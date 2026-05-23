#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo221(int * arr, int arr_len, int n);

int foo221(int * arr, int arr_len, int n) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100
Ensure Results(__return)
*/{

		int found = 0;
		int offset = arr_len;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100 &&
    (0 <= c && c <= offset) &&
(offset == arr_len@pre) &&
(n == n@pre) &&
(arr_len == arr_len@pre) &&
(arr == arr@pre) &&
(found >= 0
          loop assigns c, found)
    */
    
            for (int c = 0; c < offset; c++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 0 <= c <= offset;
              loop invariant found >= 0;
              loop assigns index, found;
            */
            for (int index = c + 1; index < offset; index++) {
				if ((arr[c] ^ arr[index]) % 2 == 1) {
					found++;
				}
			}
            
		}
		return found;
}