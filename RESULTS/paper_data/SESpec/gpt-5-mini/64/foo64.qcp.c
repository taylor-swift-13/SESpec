#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int unknown();

void foo64() 
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
    i = 1;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= a) &&
    (0 <= i) &&
    (0 <= j) &&
    (i == 1 + 2 * a) &&
    (j >= 1 + a) &&
    (a == 0 || i > 1) &&
    (a == 0 || j > 1) &&
    (b <= a * (j + i))
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