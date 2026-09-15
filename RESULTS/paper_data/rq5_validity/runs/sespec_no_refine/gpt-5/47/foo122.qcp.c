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
/*@ Inv
    ((mid@pre > 0) => (mid >= 0)) &&
((mid@pre > 0) => (lo == mid@pre - mid)) &&
((!(mid@pre > 0)) => ((hi == 2 * mid@pre)&&(lo == 0)&&(mid == mid@pre))
      loop assigns lo, hi, mid)
    */
    
    while(mid > 0){
       lo = lo + 1;
       hi = hi - 1;
       mid = mid - 1;
    }

  }