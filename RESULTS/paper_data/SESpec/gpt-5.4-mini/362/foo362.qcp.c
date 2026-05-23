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
	
 	/*@ Inv
    (1 <= c) &&
    (c == 1 || c <= size + 1) &&
    (0 <= total) &&
    (0 <= result) &&
    (result % 2 == 0) &&
    (result >= 2 * total) &&
    (total <= c / 2) &&
    (c == 1 || total <= (c - 1) / 2) &&
    (result == 0 || result >= total) &&
    ((c <= size@pre) => (result >= 0)) &&
    ((c <= size@pre) => (total >= 0)) &&
    (result == total * (total + 1)) &&
    (c == 2 * total + 1 || c == 2 * total + 2) &&
    (size == size@pre)
    */
for (int c = 1; c <= size; c++) {
			if (c % 2 == 0) {
				result += c;
				total++;
			}
		}
		return result / total;
}