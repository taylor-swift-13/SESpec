#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo203(int * data, int data_len, int array);

int foo203(int * data, int data_len, int array) 
/*@
With data_l
Require store_int_array(data, data_len, data_l) && data_len > 0 && data_len < 100
Ensure Results(__return)
*/{

		int found = 0, top = array - 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  data_l,    
    store_int_array(data, data_len, data_l) && data_len > 0 && data_len < 100 &&
    (array == array@pre) &&
(data_len == data_len@pre) &&
(data == data@pre
      loop assigns found, top)
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