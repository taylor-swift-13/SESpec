#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int unknown();

void foo63() 
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
    (a >= 0                         // a counts iterations) &&
(even(i)                       // i stays even) &&
(i >= 0                        // i non-negative and grows) &&
(j == i + 1                    // j always equals i+1) &&
(b == a                        // each iteration adds (j - i)==1 to b
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