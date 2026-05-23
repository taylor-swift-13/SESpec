#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (is_even : Z -> Prop) */

void foo53() 
/*@

Require emp

Ensure emp
*/{

    int x;
    int y;

    x = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (is_even(y) => (0 <= x && x <= 100)) &&
    (!is_even(y) => (x <= 0)) &&
    (is_even(y) => (x % 10 == 0)) &&
    (x % 5 == 0) &&
    (is_even(y) || x <= 0) &&
    (!(x < 99) => (is_even(y) && x == 100)) &&
    (x <= 100) &&
    (x % 5 == 0)
    */
    
    while (x < 99) {
       if (y % 2 == 0)
         x += 10;
       else
         x -= 5;
    }

  }