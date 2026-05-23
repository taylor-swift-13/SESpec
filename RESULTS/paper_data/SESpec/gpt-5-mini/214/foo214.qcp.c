#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo214(int num);

int foo214(int num) 
/*@

Require emp
Ensure Results(__return)
*/{

        int *catalan = (int *)malloc(sizeof(int) * (num + 1));
int catalan_len = num + 1;
        catalan[0] = 1;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (1 <= i && i <= num + 1 || i == 1) &&
(catalan_len == num + 1
      loop assigns i, catalan_l[0 .. catalan_len - 1])
    */
    
    for (int i = 1; i <= num; i++) {
        catalan[i] = 0;

        /*@
          loop invariant 0 <= j <= i;
          loop invariant catalan_len == num + 1;
          loop assigns j, catalan[i];
        */
        for (int j = 0; j < i; j++) {
            catalan[i] += catalan[j] * catalan[i - j - 1];
        }
    }
        return catalan[num];
}