#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo306(int n);

int foo306(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int *lucas = (int *)malloc(sizeof(int) * (n + 1));
int lucas_len = n + 1;
        lucas[0] = 2;
        lucas[1] = 1;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (2 <= i && i <= n+1 || i == 2 // (syntactic placeholder removed below)
          loop assigns i, lucas_l[2..n])
    */
    
            for (int i = 2; i <= n; i++) {
            lucas[i] = lucas[i - 1] + lucas[i - 2];
        }
        return lucas[n];
}