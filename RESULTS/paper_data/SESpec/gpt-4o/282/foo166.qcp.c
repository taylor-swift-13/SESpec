#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

const char * foo166(int num);

const char * foo166(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (1 <= c && c <= num + 1) &&
(result == count_divisors(num, c - 1)) &&
(num == num@pre
      loop assigns c, result)
    */
    
    for (int c = 1; c <= num; c++) {
        if (num % c == 0) {
            result++;
        }
    }
		if (result % 2 == 0) {
			return "Even";
		} else {
			return "Odd";
		}
}