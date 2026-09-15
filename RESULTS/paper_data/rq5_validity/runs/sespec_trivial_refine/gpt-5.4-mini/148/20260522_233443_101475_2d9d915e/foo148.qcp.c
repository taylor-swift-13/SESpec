#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo148(int n);

int foo148(int n) 
/*@

Require emp
Ensure (n == 1 && n % 2 != 0 && n > 0 && n@pre > 0 && __return == 1) || (n != 1 && n % 2 != 0 && n > 0 && n@pre > 0 && __return == 0) || (n <= 0 && __return == 0)
*/
{

        if(n <= 0) {
            return 0;
        }
       
  /*@ Inv
    (n > 0)
    */
while (n % 2 == 0) {
            n /= 2;
        }
        return n == 1;
}