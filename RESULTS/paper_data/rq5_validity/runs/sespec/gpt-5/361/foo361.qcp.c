#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo361(int size) 
/*@

Require emp
Ensure Results(__return)
*/{

		int average = 0;
		int total = 0;
	
 	/*@ Inv
    (1 <= j) &&
    (size == size@pre) &&
    (average >= 0) &&
    (total >= 0) &&
    (total <= j - 1) &&
    (total == (j - 1) / 2) &&
    (average == ((j - 1) / 2) * (((j - 1) / 2) + 1))
    */
for (int j = 1; j <= size; j++) {
			if (j % 2 == 0) {
				average += j;
				total++;
			}
		}
		return average / total;
}