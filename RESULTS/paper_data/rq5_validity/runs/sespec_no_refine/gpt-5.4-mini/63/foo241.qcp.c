#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int unknown();

void foo241() 
/*@

Require emp

Ensure emp
*/{

    int i;
    int j;
    int a;
    int b;

    a = 0;
    b = 0;
    j = 1;
    i = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (i >= 0) &&
(j >= 1) &&
(a == i / 2) &&
(j == i + 1) &&
(i % 2 == 0
      loop assigns a, b, i, j)
    */
    
    while (unknown()) {
       a = a + 1;
       b = b + j - i;
       i = i + 2;
       if (i % 2 == 0){
       j = j + 2;
      }
       else{
       j = j + 1;
      }
      }

  }