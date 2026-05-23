#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int unknown();

void foo79(int y,int x1,int x2,int x3) 
/*@

Require emp
Ensure emp
*/{
  int c = 0;
  int z = 36 * y;

 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (z == 36 * y@pre + c) &&
    (0 <= c && c <= 36) &&
    (exists (k:Z), 0 <= k && k == c && z == 36 * y@pre + k) &&
    (z >= 36 * y@pre && z <= 36 * y@pre + 36) &&
    ((z - 36 * y@pre) == c) &&
    (c >= 0 && c <= 36) &&
    (z == 36 * y@pre + c) &&
    (x3 == x3@pre) &&
    (x2 == x2@pre) &&
    (x1 == x1@pre) &&
    (y == y@pre)
    */
    
  while (unknown()) {
    if ( c < 36 )
    {
      z  = z + 1;
      c  = c + 1;
    }
  }

  }