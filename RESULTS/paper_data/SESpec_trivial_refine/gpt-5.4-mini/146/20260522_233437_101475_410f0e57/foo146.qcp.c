#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo146(int n);

int foo146(int n) 
/*@

Require emp
Ensure (n == 1 && n % 4 != 0 && n > 0 && n@pre > 0 && __return == 1) || (n != 1 && n % 4 != 0 && n > 0 && n@pre > 0 && __return == 0) || (n <= 0 && __return == 0)
*/
{

        if(n <= 0) {
            return 0;
        }
       
  /*0*/ 
 /*@ Inv
    (n > 0)
    */
while (n % 4 == 0) {
            n /= 4;
        }
        return n == 1;
}