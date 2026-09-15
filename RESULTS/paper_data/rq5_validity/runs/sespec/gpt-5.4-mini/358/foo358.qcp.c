#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo358(int size) 
/*@

Require emp
Ensure Results(__return)
*/{

		int average = 0;
		int total = 0;
	
 	/*@ Inv
    (1 <= index && index <= size + 1) &&
    (0 <= total && total <= index / 2) &&
    (0 <= average) &&
    (average == total * total) &&
    (total == index / 2) &&
    ((index <= size) => (average == total * total)) &&
    ((index <= size) => (total == index / 2)) &&
    (size == size@pre)
    */
for (int index = 1; index <= size; index++) {
			if (index % 2 != 0) {
				average += index;
				total++;
			}
		}
		return average / total;
}