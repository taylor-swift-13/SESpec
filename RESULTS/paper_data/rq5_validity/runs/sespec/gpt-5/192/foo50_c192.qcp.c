#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo50_c192(int count);

int foo50_c192(int count) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *w = (int *)malloc(sizeof(int) * (count + 1));
int w_len = count + 1;
		int *C = (int *)malloc(sizeof(int) * (count + 1));
int C_len = count + 1;
		w[0] = 1;
		w[1] = 0;
		C[0] = 0;
		C[1] = 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (2 <= index && index <= count + 1) &&
(w_len == count + 1 && C_len == count + 1) &&
((forall (k:Z), 2 <= k && k < index => k <= count)) &&
((forall (k:Z), 2 <= k && k < index => 0 <= k-2 && 0 <= k-1 < index)) &&
(w_l[0] == w_l[0] && w_l[1] == w_l[1] && C_l[0] == C_l[0] && C_l[1] == C_l[1]
      loop assigns index, w_l[0 .. w_len-1], C_l[0 .. C_len-1])
    */
    
    for (int index = 2; index <= count; index++) {
        w[index] = w[index - 2]
                + 2 * C[index - 1];
        C[index] = w[index - 1] + C[index - 2];
    }
		return w[count];
}