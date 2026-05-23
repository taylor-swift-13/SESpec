#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int unknown();

void foo168_c51() 
/*@

Require emp

Ensure emp
*/{

    int x;
    int y;
    int z;
    int w;

    x = 0;
    y = 0;
    z = 0;
    w = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= w) &&
(0 <= x && x <= w        // x increments by at most 1 per iteration, starts at 0) &&
(z == 10 * w        // z increases by 10 each iteration, starts at 0
      loop assigns x, y, w, z)
    */
    
    while(unknown()){
       if(x >= 4){
           x = x + 1;
           y = y + 2;
       }
       else if(y > 10 * w && z >= 100 * x){
           y = 0 - y;
       }
       else{
           x = x + 1;
           y = y + 100;
       }
       w = w + 1;
       z = z + 10;
    }

  }