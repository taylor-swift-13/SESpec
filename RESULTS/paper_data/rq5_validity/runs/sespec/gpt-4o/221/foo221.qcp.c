#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_odd_xor_pairs : Z -> Z -> Z -> Z) */
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
    (found >= 0) &&
    (offset == arr_len@pre) &&
    (n == n@pre) &&
    (arr_len == arr_len@pre) &&
    (arr == arr@pre)
    */
for (int c = 0; c < offset; c++) {

        /*@
          loop invariant c + 1 <= index <= offset;
          loop invariant found >= 0;
          loop invariant offset == \at(arr_len, Pre);
          loop invariant n == \at(n, Pre);
          loop invariant arr_len == \at(arr_len, Pre);
          loop invariant arr == \at(arr, Pre);
          loop assigns index, found;
        */
        /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (c + 1 <= index && index <= offset) &&
    (found >= 0) &&
    (offset == arr_len@pre) &&
    (n == n@pre) &&
    (arr_len == arr_len@pre) &&
    (arr == arr@pre)
    */
for (int index = c + 1; index < offset; index++) {
            if ((arr[c] ^ arr[index]) % 2 == 1) {
                found++;
            }
        }
    }
		return found;
}