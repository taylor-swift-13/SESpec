#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo69_c144(int n, int time);

int foo69_c144(int n, int time) 
/*@

Require emp
Ensure (time@pre % (n - 1) * 2 >= n && __return == n * 2 - time@pre % (n - 1) * 2 - 1) || (time@pre % (n - 1) * 2 < n && __return == time@pre % (n - 1) * 2 + 1)
*/
{

        time = time % (n - 1) * 2;
        if (time < n) {
            return time + 1;
        }
        return n * 2 - time - 1;
}