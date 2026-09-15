#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo223(int * arr, int arr_len, int n);

int foo223(int * arr, int arr_len, int n) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100
Ensure Results(__return)
*/{

		int result = 0;
		int offset = arr_len;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) && arr_len > 0 && arr_len < 100 &&
    (0 <= c) &&
(offset == arr_len) &&
(n == n@pre) &&
(arr_len == arr_len@pre) &&
(arr == arr@pre) &&
(result >= 0
          loop assigns c, result)
    */
    
        for (int c = 0; c < offset; c++) {
			
            /*@
          loop invariant 0 <= c <= offset;
          loop invariant 0 <= result;
          loop assigns c, result;
        */
        for (int index = c + 1; index < offset; index++) {
			if ((arr[c] ^ arr[index]) % 2 == 1) {
				result++;
			}
		}
            
	}
		return result;
}