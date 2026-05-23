#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo147(int count, int m);

int foo147(int count, int m) 
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
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (3 <= d) &&
((d <= count) => 3 <= d && d <= count) &&
(div_len == count + 1) &&
(div_l[0] == 1 && div_l[1] == m && div_l[2] == m * m) &&
(forall (k:Z), 3 <= k && k < d => div_l[k] == ((m - 1) * (div_l[k - 1] + div_l[k - 2])) % w
      loop assigns d, div_l[0 .. div_len - 1])
    */
    
    for (int d = 3; d <= count; d++) {
        div[d] = ((m - 1)
                * (div[d - 1] + div[d - 2])) % w;
    }
		return div[count];
}