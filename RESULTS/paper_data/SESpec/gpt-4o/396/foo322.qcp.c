#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo322(int p);

int foo322(int p) 
/*@

Require emp
Ensure Results(__return)
*/{

		int even = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (p == p@pre
      loop assigns c, even)
    */
    
    for (int c = 1; c <= p; c++) {
        int count = 2 * c;
        even = even + (count * count * count * count);
    }
		return even;
}