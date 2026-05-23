#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo201_c299(int * data, int data_len, int array);

int foo201_c299(int * data, int data_len, int array) 
/*@
With data_l
Require store_int_array(data, data_len, data_l) && data_len > 0 && data_len < 100
Ensure Results(__return)
*/{

		int i = 0, top = array - 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (i < top) {
			int p = i + (top - i) / 2;
			if (data[p] < data[p + 1]) {
				i = p + 1;
			} else {
				top = p;
			}
		}
		return i;
}