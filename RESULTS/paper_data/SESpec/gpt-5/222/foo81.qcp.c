#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo81(int * arr, int arr_len, int n);

int foo81(int * arr, int arr_len, int n) 
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
    (0 <= index && index <= offset) &&
(offset == arr_len@pre) &&
(arr_len == arr_len@pre) &&
(arr == arr@pre) &&
(n == n@pre) &&
(forall (k:Z), 0 <= k && k < offset => arr_l[k] == arr_l[k]@pre) &&
(0 <= result
          loop assigns index, result)
    */
    
            for (int index = 0; index < offset; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index < offset;
          loop invariant index + 1 <= c <= offset;
          loop invariant offset == \at(arr_len,Pre);
          loop invariant \forall integer k; 0 <= k < offset ==> arr[k] == \at(arr[k], Pre);
          loop invariant 0 <= result;
          loop assigns result, c;
            */
            for (int c = index + 1; c < offset; c++) {
				if ((arr[index] ^ arr[c]) % 2 == 1) {
					result++;
				}
			}
            
		}
		return result;
}