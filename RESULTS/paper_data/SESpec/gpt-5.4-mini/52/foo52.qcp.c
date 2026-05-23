#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int unknown();

void foo52() 
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
    (x <= w) &&
    (0 <= w) &&
    (y % 2 == 0) &&
    (z == 10 * w) &&
    (x >= 0) &&
    (z >= 0) &&
    (x <= w) &&
    (w >= x) &&
    (z == 10 * w) &&
    (y % 2 == 0)
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