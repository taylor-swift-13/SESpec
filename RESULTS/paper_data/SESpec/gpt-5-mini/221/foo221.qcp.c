#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (pairs_from_c : Z -> Z -> Z -> Z -> Z) */
/*@ Extern Coq (pairs_range : Z -> Z -> Z -> Z -> Z) */
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
    (found >= 0) &&
    (forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre)
    */
for (int c = 0; c < offset; c++) {

        /*@
          loop invariant found >= 0;
          loop invariant \forall integer i; 0 <= i < c ==> 0 <= arr[i] <= 100;
          loop assigns index, found;
        */
        /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (found >= 0) &&
    (forall (i:Z), 0 <= i && i < c => 0 <= arr_l[i] && arr_l[i] <= 100)
    */
for (int index = c + 1; index < offset; index++) {
            if ((arr[c] ^ arr[index]) % 2 == 1) {
                found++;
            }
        }
    }
		return found;
}