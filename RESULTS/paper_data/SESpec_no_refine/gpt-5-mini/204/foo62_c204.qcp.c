#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo62_c204(int * ints, int ints_len, int array);

int foo62_c204(int * ints, int ints_len, int array) 
/*@
With ints_l
Require store_int_array(ints, ints_len, ints_l) && ints_len > 0 && ints_len < 100
Ensure Results(__return)
*/{

		int find = 0;
		int offset = 0;
		int max = 1;

	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (offset < array && max < array) {
			if (ints[offset] == ints[max]) {
				offset++;
				max++;
				find++;
			} else if (ints[offset] > ints[max]) {
				offset++;
			} else {
				max++;
			}
		}

		return find;
}