#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo359(int size) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 0;
		int total = 0;
	
 	/*@ Inv
    (1 <= c && c <= size + 1) &&
    (0 <= total) &&
    (0 <= ret) &&
    (size == size@pre) &&
    (c == 2 * total || c == 2 * total + 1) &&
    (ret == total * total)
    */
for (int c = 1; c <= size; c++) {
			if (c % 2 != 0) {
				ret += c;
				total++;
			}
		}
		return ret / total;
}