#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo187(int num);

int foo187(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *result = (int *)malloc(sizeof(int) * (num + 1));
int result_len = num + 1;
		result[0] = 2;
		result[1] = 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (2 <= l) &&
((l <= num) => (l <= num + 1)) &&
(result_len == num + 1) &&
(result_l[0] == 2) &&
(result_l[1] == 1) &&
(forall (k:Z), 2 <= k && k < l => result_l[k] == result_l[k-1] + result_l[k-2]) &&
(forall (k:Z), 0 <= k && k < l => result_l[k] == fib(k)
      loop assigns l, result_l[0 .. result_len-1])
    */
    
    for (int l = 2; l <= num; l++) {
        result[l] = result[l - 1]
                    + result[l - 2];
    }
		return result[num];
}