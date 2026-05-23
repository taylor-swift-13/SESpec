#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo82(int * arr, int arr_len, int n);

int foo82(int * arr, int arr_len, int n) 
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
    (0 <= c && c <= offset) &&
(offset == arr_len) &&
(arr_len == arr_len@pre) &&
(n == n@pre) &&
(arr == arr@pre) &&
(result >= 0
          loop assigns c, result)
    */
    
        for (int c = 0; c < offset; c++) {
			
            /* >>> LOOP INVARIANT TO FILL <<< */
            /*@
              loop invariant c + 1 <= index <= offset;
              loop invariant result >= 0;
              loop invariant offset == arr_len;
              loop assigns index, result;
            */
            for (int index = c + 1; index < offset; index++) {
				if ((arr[c] ^ arr[index]) % 2 == 1) {
					result++;
				}
			}
            
		}
		return result;
}