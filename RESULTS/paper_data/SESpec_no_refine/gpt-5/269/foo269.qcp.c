#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo269(int dim, int w);

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
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (div_len == dim + 1
          loop assigns d, div_l[0..div_len-1])
    */
    
            for (int d = 3; d <= dim; d++) {
			div[d] = ((w - 1)
					* (div[d - 1] + div[d - 2])) % count;
		}
		return div[dim];
}