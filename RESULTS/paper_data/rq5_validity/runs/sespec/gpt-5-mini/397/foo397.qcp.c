#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo397(int p);

int foo397(int p) 
/*@

Require emp
Ensure Results(__return)
*/{

		int even = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (1 <= c) &&
((c <= p@pre) => (even == sum_fourth_powers(c-1))) &&
((c <= p@pre) => is_even(even)) &&
((!(c <= p@pre)) => ((even == sum_fourth_powers(p@pre)) && (p == p@pre))) &&
(p == p@pre
      loop assigns c, even)
    */
    
    for (int c = 1; c <= p; c++) {
		int tmp = 2 * c;
		even = even + (tmp * tmp * tmp * tmp);
	}
		return even;
}