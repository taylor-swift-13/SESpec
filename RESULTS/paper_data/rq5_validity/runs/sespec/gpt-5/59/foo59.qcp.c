#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int unknown();

void foo59() 
/*@

Require emp

Ensure emp
*/{

    unsigned int x;
    unsigned int y;

    y = 1;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0u <= y <= 1u) &&
    (y == 1 || y == 0) &&
    (x % 3 == 0 || x % 3 == 1 || x % 3 == 2) &&
    (x >= 0u)
    */
    
    while(unknown()){
      if(x % 3 == 1){
        x = x + 2;
        y = 0;
      }
      else{
        if(x % 3 == 2){
          x = x + 1;
          y = 0;
        }
        else{
          if(unknown()){
            x = x + 4;
            y = 1;
          }
          else{
            x = x + 5;
            y = 1;
          }
        }
      }
    }

  }