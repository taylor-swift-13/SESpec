#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo391(int n);

int foo391(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int i = 1;
        int square = 1;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((1 <= n@pre) => (1 <= i)) &&
((!(1 <= n@pre)) => ((square == 1)&&(i == 1)&&(n == n@pre))) &&
(n == n@pre
          loop assigns square, i)
    */
    
            while (square <= n) {
            square = i*i;
            i++;
        }
        return square;
}