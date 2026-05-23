#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo306(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int *lucas = (int *)malloc(sizeof(int) * (n + 1));
int lucas_len = n + 1;
        lucas[0] = 2;
        lucas[1] = 1;
       
  /*0*/ 
 /*@ Inv
    (2 <= i && i <= n + 1) &&
    (forall (k:Z), 2 <= k && k < i => lucas[k] == lucas[k - 1] + lucas[k - 2])
    */
for (int i = 2; i <= n; i++) {
            lucas[i] = lucas[i - 1] + lucas[i - 2];
        }
        return lucas[n];
}