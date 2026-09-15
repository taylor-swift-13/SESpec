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
    (1 <= c && c <= size + 1) &&
    (0 <= average) &&
    (size == size@pre) &&
    (average >= total) &&
    (average <= total * size@pre) &&
    (total >= 0) &&
    (total > 0 => (exists (k:Z), 1 <= k && k < c && k % 2 != 0)) &&
    ((c <= size@pre) => (average >= 0))
    */
for (int c = 1; c <= size; c++) {
		if (c % 2 != 0) {
			average += c;
			total++;
		}
	}
		return average / total;
}