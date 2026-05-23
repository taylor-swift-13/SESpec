#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (fib_mod : Z -> Z) */
int foo292(int seed) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *p = (int *)malloc(sizeof(int) * (seed + 1));
int p_len = seed + 1;
		p[0] = 0;
		p[1] = 1;
	
 	/*@ Inv
    (2 <= count && count <= seed + 1)
    */
for (int count = 2; count <= seed; count++) {
        p[count] = (2 * p[count - 1] + p[count - 2]) % 1000000000;
    }
		return p[seed];
}