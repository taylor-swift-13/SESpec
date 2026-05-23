#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (ipow : Z -> Z -> Z) */
/*@ Extern Coq (series : Z -> Z -> Z) */

void foo83(int z,int k,int a)
/*@

Require emp
Ensure emp
*/{

    int x=a;
    int y=1;
    int c=1;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (c >= 1) &&
    (y == ipow(z, c - 1))
    */
    
            while (c < k){
   c = c + 1;
   x = x*z + a;
   y = y*z;
    }

  }