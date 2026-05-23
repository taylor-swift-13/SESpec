#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo399(int value);

int foo399(int value) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((value@pre > 0) => (result + digits10(value) == digits10(value@pre))) &&
((value@pre > 0) => (value >= 0)) &&
((value@pre > 0) => (result >= 0)) &&
((!(value@pre > 0)) => ((result == 0)&&(value == value@pre))
      loop assigns value, result)
    */
    
    while (value > 0) {
        value /= 10;
        result++;
    }
		return result;
}