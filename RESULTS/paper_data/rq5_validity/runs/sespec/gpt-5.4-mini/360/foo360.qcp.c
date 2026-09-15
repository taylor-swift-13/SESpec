#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo360(int size) 
/*@

Require emp
Ensure Results(__return)
*/{

		int average = 0;
		int total = 0;
	
 	/*@ Inv
    (1 <= c) &&
    (c <= size + 1) &&
    (total == c / 2) &&
    (average == total * total) &&
    (average >= 0) &&
    (total >= 0) &&
    ((c % 2 == 0) => (average == total * total)) &&
    ((c <= size) => (average == total * total)) &&
    ((c <= size) => (average >= total)) &&
    ((c <= size) => (total == c / 2)) &&
    (size == size@pre)
    */
for (int c = 1; c <= size; c++) {
			if (c % 2 != 0) {
				average += c;
				total++;
			}
		}
		return average / total;
}