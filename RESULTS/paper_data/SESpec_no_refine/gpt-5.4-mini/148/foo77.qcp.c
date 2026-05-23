#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo77(int n);

int foo77(int n) 
/*@

Require emp
Ensure (n == 1 && n % 2 != 0 && n > 0 && __return == 1) || (n != 1 && n % 2 != 0 && n > 0 && __return == 0) || (n <= 0 && __return == 0)
*/
{

        if(n <= 0) {
            return 0;
        }
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (n % 2 == 0) {
            n /= 2;
        }
        return n == 1;
}