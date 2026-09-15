#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo222(int * arr, int arr_len, int n);

int foo222(int * arr, int arr_len, int n) 
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
    (0 <= index && index <= arr_len@pre) &&
(0 <= result) &&
(offset == arr_len@pre) &&
(n == n@pre) &&
(arr_len == arr_len@pre) &&
(arr == arr@pre) &&
(forall (k:Z), 0 <= k && k < arr_len@pre => 0 <= arr_l[k] <= 100
      loop assigns index, result)
    */
    
    for (int index = 0; index < offset; index++) {
        
        /*@
          loop invariant 0 <= c && c <= offset;
          loop invariant 0 <= index && index < offset;
          loop invariant 0 <= result;
          loop assigns result;
        */
        for (int c = index + 1; c < offset; c++) {
            if ((arr[index] ^ arr[c]) % 2 == 1) {
                result++;
            }
        }
        
    }
		return result;
}