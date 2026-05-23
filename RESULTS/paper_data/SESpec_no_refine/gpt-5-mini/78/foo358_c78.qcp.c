#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int unknown();

void foo358_c78(int y) 
/*@

Require emp
Ensure emp
*/{
  int c = 0;
  int z = 36 * y;

 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (unknown()) {

    if ( c < 36 )
    {
    z  = z + 1;
    c  = c + 1;
    }
  }

}