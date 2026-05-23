#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo398(int x,int y)
/*@

Require emp
Ensure Results(__return)
*/{

  int q=0;
  int r=0;

 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((x@pre > y@pre * 0 + 0) => (q >= 0)) &&
((x@pre > y@pre * 0 + 0) => (((r == 0)&&(q == 0)&&(y == y@pre)&&(x == x@pre)) || (r >= 0))) &&
((!(x@pre > y@pre * 0 + 0)) => ((r == 0)&&(q == 0)&&(y == y@pre)&&(x == x@pre))) &&
(y == y@pre) &&
(x == x@pre
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