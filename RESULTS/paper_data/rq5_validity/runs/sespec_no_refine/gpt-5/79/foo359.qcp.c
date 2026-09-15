#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int unknown();

void foo359(int y,int x1,int x2,int x3) 
/*@

Require emp
Ensure emp
*/{
  int c = 0;
  int z = 36 * y;

 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (z - c == 36 * y) &&
(0 <= c && c <= 36
    loop assigns z, c)
    */
    
  while (unknown()) {

    if ( c < 36 )
    {
      z  = z + 1;
      c  = c + 1;
    }
  }

  }