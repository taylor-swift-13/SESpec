#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo89(int k)
/*@

Require emp
Ensure emp
*/{

    int y=0;
    int x=0;
    int c=0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (k == k@pre) &&
(c == y
      loop assigns c, y, x)
    */
    
    while(c < k){
        c = c + 1 ;
        y = y + 1;
        x = y*y*y*y*y+x;
    }

}