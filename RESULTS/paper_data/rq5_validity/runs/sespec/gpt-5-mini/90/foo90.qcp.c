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
    (0 <= q) &&
    (0 <= r) &&
    ((y > 0) => r < y) &&
    (x == x@pre) &&
    (y == y@pre) &&
    (0 <= q * y + r) &&
    ((exists (k:Z), 0 <= k && k == q + r)) &&
    (q >= 0) &&
    (r >= 0 && (y > 0 => r < y)) &&
    ((x@pre > y@pre * 0 + 0) => (q >= 0)) &&
    ((x@pre > y@pre * 0 + 0) => (q == q)) &&
    ((x@pre > y@pre * 0 + 0) => (((r == 0)&&(q == 0)&&(y == y@pre)&&(x == x@pre)) || (r >= 0 && q >= 0))) &&
    ((!(x@pre > y@pre * 0 + 0)) => ((r == 0)&&(q == 0)&&(y == y@pre)&&(x == x@pre)))
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