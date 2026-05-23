#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo362(int size) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 0;
		int total = 0;
	
 	/*0*/ 
 /*@ Inv
    (1 <= c && c <= size + 1) &&
    (total == \numof(int i, 1, c - 1, i % 2 == 0)) &&
    (result == \sum(int i, 1, c - 1, (i % 2 == 0 ? i : 0))) &&
    (total >= 0) &&
    (result >= 0)
    */
for (int c = 1; c <= size; c++) {
			if (c % 2 == 0) {
				result += c;
				total++;
			}
		}
		return result / total;
}