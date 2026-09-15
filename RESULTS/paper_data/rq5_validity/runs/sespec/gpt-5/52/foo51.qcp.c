#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int unknown();

void foo51() 
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
    (0 <= z) &&
    (z == 10 * w) &&
    (x >= 0) &&
    ((z % 10) == 0) &&
    (exists (t:Z), t >= 0 && w == t) &&
    (forall (k:Z), 0 <= k && k < w => z >= 10 * k) &&
    (forall (k:Z), 0 <= k && k < w => z - 10 * k >= 0) &&
    ((y >= 0) => (y % 1 == 0)) &&
    ((x >= 4) => (y % 2 == 0)) &&
    ((x < 4) => (y % 100 == 0)) &&
    ((w >= 0) => (z == 10 * w)) &&
    (x >= 0) &&
    (x <= w + 1) &&
    (z == 10 * w) &&
    (z >= 0) &&
    (w >= 0) &&
    (w >= 0)
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