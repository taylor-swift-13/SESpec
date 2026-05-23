#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo367(int n);

int foo367(int n) 
/*@

Require emp
Ensure (2 > n / 2 && __return == n) || (n % 2 == 0 && 2 <= n / 2 && __return == 2)
*/
{

        int i = 2;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (i <= n / i) {
            if (n % i == 0) {
                return i;
            }
            i++;
        }
        return n;
}