#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo391(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int i = 1;
        int square = 1;
       
  /*@ Inv
    ((square == (i - 1) * (i - 1)) || (i == 1 && square == 1)) &&
    (i >= 1)
    */
while (square <= n) {
            square = i*i;
            i++;
        }
        return square;
}