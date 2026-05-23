#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (sum_odd : Z -> Z -> Z) */
/*@ Extern Coq (count_odd : Z -> Z -> Z) */
int foo359(int size) 
/*@

Require emp
Ensure Results(__return)
*/{

		int ret = 0;
		int total = 0;
	
 	/*@ Inv
    (1 <= c && c <= size + 1) &&
    (size == size@pre)
    */
for (int c = 1; c <= size; c++) {
        if (c % 2 != 0) {
            ret += c;
            total++;
        }
    }
		return ret / total;
}