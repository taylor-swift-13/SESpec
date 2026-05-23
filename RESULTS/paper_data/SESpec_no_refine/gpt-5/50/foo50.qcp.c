#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo50(int i, int j, int k) 
/*@

Require emp
Ensure emp
*/{

    int n;
    int b;

    n = 0;
    b = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while(n < (2 * k)){
       n = n + 1;
       if(b == 1){
       b = 0;
       i = i + 1;
      }
       else{
       b = 1;
       j = j + 1;
      }
      }

  }