#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo86(int k)
/*@

Require emp
Ensure emp
*/{

    int y=0;
    int x=0;
    int c=0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 < k@pre) => (foo86_goal(k@pre, c, x, y))) &&
((0 < k@pre) => (foo86_y(k@pre, c, y))) &&
((0 < k@pre) => (foo86_x(k@pre, c, x))) &&
((0 < k@pre) => (foo86_c(k@pre, c))) &&
((!(0 < k@pre)) => ((c == 0)&&(x == 0)&&(y == 0)&&(k == k@pre))) &&
(k == k@pre
          loop assigns c, y, x)
    */
    
        while(c < k){
     c = c + 1;
     y = y + 1;
     x = y * y + x;
    }

}