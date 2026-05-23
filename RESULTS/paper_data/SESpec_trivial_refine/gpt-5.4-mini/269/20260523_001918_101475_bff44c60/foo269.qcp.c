#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo269(int dim, int w) 
/*@

Require emp
Ensure Results(__return)
*/{

		int count = 1000000007;
		int *div = (int *)malloc(sizeof(int) * (dim + 1));
int div_len = dim + 1;
		div[0] = 1;
		div[1] = w;
		div[2] = w * w;
	
 	/*@ Inv
    (d >= 3)
    */
for (int d = 3; d <= dim; d++) {
			div[d] = ((w - 1)
					* (div[d - 1] + div[d - 2])) % count;
		}
		return div[dim];
}