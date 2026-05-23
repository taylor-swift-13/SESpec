#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo180(int * rot, int rot_len, int count);

int foo180(int * rot, int rot_len, int count) 
/*@
With rot_l
Require store_int_array(rot, rot_len, rot_l) && rot_len > 0 && rot_len < 100
Ensure Results(__return)
*/{

		if (count == 0) {
			return 0;
		}
		int r = 0, top = count - 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (r < top) {
			if (rot[r] < rot[top]) {
				return r + 1;
			}
			int i = (r + top) / 2;
			if (rot[i] > rot[r]) {
				r = i;
			} else {
				top = i;
			}
		}
		return r + 1;
}