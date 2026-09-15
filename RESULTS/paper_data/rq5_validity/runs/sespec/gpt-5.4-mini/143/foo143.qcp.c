#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo143(int n, int time);

int foo143(int n, int time) 
/*@

Require emp
Ensure (time@pre % ((n - 1) * 2) < n && __return == time@pre % ((n - 1) * 2) + 1) || (time@pre % ((n - 1) * 2) >= n && __return == n * 2 - time@pre % ((n - 1) * 2) - 1)
*/
{

        time %= (n - 1) * 2;
        return time < n ? time + 1 : n * 2 - time - 1;
}