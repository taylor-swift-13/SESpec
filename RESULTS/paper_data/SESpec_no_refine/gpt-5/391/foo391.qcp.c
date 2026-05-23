#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo391(int n);

int foo391(int n) 
/*@

Require emp
Ensure (1 > n && __return == 1)
*/
{

        int i = 1;
        int square = 1;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (square <= n) {
            square = i*i;
            i++;
        }
        return square;
}