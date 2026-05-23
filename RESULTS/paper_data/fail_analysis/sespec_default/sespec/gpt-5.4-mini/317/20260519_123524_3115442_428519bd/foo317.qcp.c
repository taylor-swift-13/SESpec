#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo317(int num);

int foo317(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		if (num == 1)
			return 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (2 <= size) &&
(result >= 0) &&
((size <= num / size) => (result <= size - 2)) &&
((!(size <= num / size)) => (result >= 0)
          loop assigns size, result)
    */
    
            for (int size = 2; size <= num / size; size++) {
			if (num % size == 0) {
				result++;
				if (num / size == size) {
					break;
				}
			}
		}
		return result;
}