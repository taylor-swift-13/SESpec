#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo221(int * arr, int arr_len, int n) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

		int found = 0;
		int offset = arr_len;
	
 	/*0*/ 
 /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= c && c <= offset) &&
    (found == pair_count(arr, offset, c))
    */
for (int c = 0; c < offset; c++) {
		
 	/*1*/ 
 /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= c && c <= offset) &&
    (found == pair_count(arr, offset, c)) &&
    (c + 1 <= index && index <= offset) &&
    (found == pair_count(arr, offset, c) + (\sum integer j = c + 1 j < index ((arr_l[c] ^ arr_l[j]) % 2 == 1 ? 1 : 0)))
    */
for (int index = c + 1; index < offset; index++) {
				if ((arr[c] ^ arr[index]) % 2 == 1) {
					found++;
				}
			}
		}
		return found;
}