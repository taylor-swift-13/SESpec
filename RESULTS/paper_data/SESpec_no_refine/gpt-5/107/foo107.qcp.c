#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <assert.h>
int foo107(int * x, int x_len);

int foo107(int * x, int x_len) 
/*@
With x_l
Require store_int_array(x, x_len, x_l) && x_len > 0 && x_len < 100
Ensure Results(__return)
*/{

         	assert(x_len >= 0);
         	if (x_len == 0) {
            		return -1;
        	} else {
            		int index = 0;

            	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (x_len - index > 0 && x[index] != 0) {
                		index = index + 1;
            		}
            		if (x_len - index == 0) {
               			index = -1;
            		}
            	return index;
        	}
}