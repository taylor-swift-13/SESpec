#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo122(int mid) 
/*@

Require emp
Ensure emp
*/{

    int lo;
    int hi;

    lo = 0;
    hi = 2 * mid;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while(mid > 0){
       lo = lo + 1;
       hi = hi - 1;
       mid = mid - 1;
      }

  }