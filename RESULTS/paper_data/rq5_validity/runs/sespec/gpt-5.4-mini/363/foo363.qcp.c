#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo363(int size) 
/*@

Require emp
Ensure Results(__return)
*/{

		int average = 0;
		int total = 0;
	
 	/*@ Inv
    (c >= 1) &&
    (size == size@pre) &&
    (total == (c - 1) / 2) &&
    (0 <= average) &&
    (average >= total) &&
    ((c % 2 == 0) => average >= total) &&
    ((c > 1) => total >= 0) &&
    ((c <= size@pre) => (total >= 0)) &&
    ((c <= size@pre) => (average >= 0))
    */
for (int c = 1; c <= size; c++) {
			if (c % 2 == 0) {
				average += c;
				total++;
			}
		}
		return average / total;
}