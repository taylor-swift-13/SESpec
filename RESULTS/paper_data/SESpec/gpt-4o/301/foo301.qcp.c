#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (max_index : Z -> Z -> Z -> Z) */
int foo301(int * data, int data_len, int array) 
/*@
With data_l
Require store_int_array(data, data_len, data_l)
Ensure Results(__return)
*/{

		int found = 0, top = array - 1;
	
 	/*@ Inv
    exists  data_l,    
    store_int_array(data, data_len, data_l) &&
    (array == array@pre) &&
    (data_len == data_len@pre) &&
    (data == data@pre)
    */
while (found < top) {
        int i = found + (top - found) / 2;
        if (data[i] < data[i + 1]) {
            found = i + 1;
        } else {
            top = i;
        }
    }
		return found;
}