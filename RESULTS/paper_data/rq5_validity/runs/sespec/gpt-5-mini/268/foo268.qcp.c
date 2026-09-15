#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (seq_div : Z -> Z -> Z -> Z) */
int foo268(int count, int w) 
/*@

Require emp
Ensure Results(__return)
*/{

		int result = 1000000007;
		int *div = (int *)malloc(sizeof(int) * (count + 1));
int div_len = count + 1;
		div[0] = 1;
		div[1] = w;
		div[2] = w * w;
	
 	/*@ Inv
    (3 <= d) &&
    (d <= count + 1 || d == 3) &&
    (0 <= count) &&
    (0 <= div_len && div_len == count + 1)
    */
for (int d = 3; d <= count; d++) {
			div[d] = ((w - 1)
					* (div[d - 1] + div[d - 2])) % result;
		}
		return div[count];
}