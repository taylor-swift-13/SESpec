#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo85(int a,int b)
/*@

Require emp
Ensure emp
*/{

    int x=a;
    int y=b;
    int z=0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (y >= 0) &&
    (z + x * y == a * b)
    */
    
    while(y!=0) {

     if (y%2 ==1 ){
          z = z+x;
          y = y-1;
     }
     x = 2*x;
     y = y/2;
    }

}