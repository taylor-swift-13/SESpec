#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo73_c214(int num);

int foo73_c214(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

        int *catalan = (int *)malloc(sizeof(int) * (num + 1));
int catalan_len = num + 1;
        catalan[0] = 1;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for (int i = 1; i <= num; i++) {
            catalan[i] = 0;
           
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv emp */ /*1*/ 
 for (int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i - j - 1];
            }
        }
        return catalan[num];
}