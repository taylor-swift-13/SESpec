#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo231(int * p, int p_len, int array);

int foo231(int * p, int p_len, int array) 
/*@
With p_l
Require store_int_array(p, p_len, p_l) && p_len > 0 && p_len < 100
Ensure Results(__return)
*/{

		int count = 0;
		int total = p_len;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for (int index = 0; index < total - 1; index++) {
		
 	/*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv emp */ /*1*/ 
 for (int c = index + 1; c < total; c++) {
				if (p[index] != p[c]) {
					count++;
				}
			}
		}
		return count;
}