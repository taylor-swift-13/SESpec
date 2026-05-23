#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo62(int idBitLength, int material_length, int nlen) 
/*@

Require emp
Ensure emp
*/{

    int j;
    int k;

    j = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= j)
    */
    
    while((j < idBitLength / 8) && (j < material_length)){
        j = j + 1;
    }

  }