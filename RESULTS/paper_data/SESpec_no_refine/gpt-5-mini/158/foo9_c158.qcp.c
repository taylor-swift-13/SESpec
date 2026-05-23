#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo9_c158(int n);

int foo9_c158(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        if (n <= 2) {
            return n;
        }
        int i = n * 2;
        int *factors = (int *)malloc(sizeof(int) * (n));
int factors_len = n;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for (int j = 0; j < n; j++) {
            factors[j] = j + 1;
        }
       
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv emp */ /*1*/ 
 while (1) {
           
  /*@ Print user assertion at number LoopEntry_2*/ 
/*@ Inv emp */ /*2*/ 
 for (int a = 0; a < n; a++) {
                if (i % factors[a] != 0) {
                    i += n;
                    break;
                }
                if (factors[a] == factors[n - 1] && i % factors[a] == 0) {
                    return i;
                }
            }
        }
}