#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (max_index : Z -> Z -> Z -> Z) */
int foo300(int * array, int array_len, int Array) 
/*@
With array_l
Require store_int_array(array, array_len, array_l)
Ensure Results(__return)
*/{

		int found = 0, top = Array - 1;
	
 	/*@ Inv
    exists  array_l,    
    store_int_array(array, array_len, array_l) &&
    (Array == Array@pre) &&
    (array_len == array_len@pre) &&
    (array == array@pre) &&
    (forall (k:Z), 0 <= k && k < array_len => array_l[k] == array_l[k]@pre)
    */
while (found < top) {
        int i = found + (top - found) / 2;
        if (array[i] < array[i + 1]) {
            found = i + 1;
        } else {
            top = i;
        }
    }
		return found;
}