#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo312(int n, int k);

int foo312(int n, int k) 
/*@

Require emp
Ensure (1 > k && __return == 1)
*/
{

        int res = 1;
        int i = 1;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (i <= k) {
            res *= (n - i + 1);
            i++;
        }
        return res;
}