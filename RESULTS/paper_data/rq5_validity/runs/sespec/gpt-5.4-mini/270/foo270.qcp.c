#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (foo270_seq : Z -> Z -> Z) */
int foo270(int count, int m) 
/*@

Require emp
Ensure Results(__return)
*/{

		int w = 1000000007;
		int *div = (int *)malloc(sizeof(int) * (count + 1));
int div_len = count + 1;
		div[0] = 1;
		div[1] = m;
		div[2] = m * m;
	
 	/*@ Inv
    (d >= 3) &&
    (div[0] == 1) &&
    (div[1] == m) &&
    (div[2] == m * m)
    */
for (int d = 3; d <= count; d++) {
			div[d] = ((m - 1)
					* (div[d - 1] + div[d - 2])) % w;
		}
		return div[count];
}