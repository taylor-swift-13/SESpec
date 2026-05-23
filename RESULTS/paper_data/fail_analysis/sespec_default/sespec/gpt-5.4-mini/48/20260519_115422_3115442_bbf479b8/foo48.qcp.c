#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int unknown();

void foo48() 
/*@

Require emp

Ensure emp
*/{

    int x;
    int y;
    int xa;
    int ya;

    xa = 0;
    ya = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (\true
      loop assigns x, y, xa, ya)
    */
    
    while(unknown()){
       x = xa + ya * 2 + 1;
       if(unknown()){
       y = ya - xa * 2 + x;
      }
       else{
       y = ya - xa * 2 - x;
      }
       xa = x - y * 2;
       ya = x * 2 + y;
      }

  }