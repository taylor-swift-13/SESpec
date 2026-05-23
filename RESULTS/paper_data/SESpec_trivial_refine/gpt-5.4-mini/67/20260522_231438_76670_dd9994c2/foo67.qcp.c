#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo67(int n) 
/*@

Require emp
Ensure emp
*/{

    int i;
    int k;
    int j;

    i = 0;
    j = 0;
    k = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while(i < n){
       i = i + 3;
       if((i % 2) != 0)
       j = j + 3;
       else
       k = k + 3;
      }

  }