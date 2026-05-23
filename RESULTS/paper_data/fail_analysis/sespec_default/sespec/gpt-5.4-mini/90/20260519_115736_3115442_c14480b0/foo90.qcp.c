#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo90(int x,int y)
/*@

Require emp
Ensure emp
*/{

  int q=0;
  int r=0;

 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (y == y@pre) &&
(x == x@pre) &&
(q >= 0) &&
(r >= 0) &&
(r < y || y <= 0) &&
((r == 0 && q == 0) || q > 0 || r > 0
    loop assigns r, q)
    */
    
  while(x > y * q + r) {
      if (r == y - 1){
          r = 0;
          q += 1;
      }
      else{
          r += 1;
      }

  }

}