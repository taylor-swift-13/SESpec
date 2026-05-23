#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (odd_count : Z -> Z) */
int foo358(int size) 
/*@

Require emp
Ensure Results(__return)
*/{

		int average = 0;
		int total = 0;
	
 	/*@ Inv
    (average == total * total) &&
    (total == index / 2) &&
    (index >= 1)
    */
for (int index = 1; index <= size; index++) {
			if (index % 2 != 0) {
				average += index;
				total++;
			}
		}
		return average / total;
}