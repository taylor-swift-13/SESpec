#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (pell_rec : Z -> Z) */

int foo304(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int *pell = (int *)malloc(sizeof(int) * (n + 1));
int pell_len = n + 1;
        pell[0] = 0;
        pell[1] = 1;
       
  /*0*/ 
 /*@ Inv
    (2 <= i && i <= n + 1) &&
    (pell[i - 1] == pell_rec(i - 1)) &&
    (pell[i - 2] == pell_rec(i - 2)) &&
    (forall (k:Z), 0 <= k && k < i => pell[k] == pell_rec(k))
    */
for (int i = 2; i <= n; i++) {
            pell[i] = (2 * pell[i - 1] + pell[i - 2]) % 1000000000;
        }
        return pell[n];
}