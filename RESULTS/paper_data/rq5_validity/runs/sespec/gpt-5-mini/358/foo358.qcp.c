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
    (index >= 1) &&
    (0 <= total && total <= index - 1) &&
    (0 <= average) &&
    ((size@pre >= 0) => (total <= size@pre)) &&
    (total > 0 => (exists (k:Z), 1 <= k && k < index && k % 2 != 0)) &&
    (size == size@pre) &&
    ((size@pre < 1) => (average == 0 && total == 0))
    */
for (int index = 1; index <= size; index++) {
		if (index % 2 != 0) {
			average += index;
			total++;
		}
	}
		return average / total;
}