#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo301(int * data, int data_len, int array);

int foo301(int * data, int data_len, int array) 
/*@
With data_l
Require store_int_array(data, data_len, data_l) && data_len > 0 && data_len < 100
Ensure Results(__return)
*/{

		int found = 0, top = array - 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
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