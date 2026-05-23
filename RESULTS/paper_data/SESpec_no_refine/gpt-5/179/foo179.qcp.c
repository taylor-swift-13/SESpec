#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo179(int * array, int array_len, int count);

int foo179(int * array, int array_len, int count) 
/*@
With array_l
Require store_int_array(array, array_len, array_l) && array_len > 0 && array_len < 100
Ensure Results(__return)
*/{

		if (count == 0) {
			return 0;
		}
		int r = 0, top = count - 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (r < top) {
			if (array[r] < array[top]) {
				return r + 1;
			}
			int end = (r + top) / 2;
			if (array[end] > array[r]) {
				r = end;
			} else {
				top = end;
			}
		}
		return r + 1;
}