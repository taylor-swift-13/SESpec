#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (odd_sum : Z -> Z) */
/*@ Extern Coq (odd_count : Z -> Z) */
int foo359(int size) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 0;
		int total = 0;
	
 	/*@ Inv
    emp
    */
for (int c = 1; c <= size; c++) {
		if (c % 2 != 0) {
			ret += c;
			total++;
		}
	}
		return ret / total;
}