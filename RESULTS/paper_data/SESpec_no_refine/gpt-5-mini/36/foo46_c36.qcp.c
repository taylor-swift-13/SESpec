#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <assert.h>

double foo46_helper1_c36(long long l);
double foo46_c36(double x);

double foo46_helper1_c36(long long l) /*@

Require emp
Ensure Results(__return)
*/
{
    assert(l < 100L && l > -100L);
    return (double)l;
}

double foo46_c36(double x) 
/*@

Require emp
Ensure Results(__return)
*/{
    if (x < 0.0) x *= 10.0;
    else x /= 10.0;
    long long l = (long long)x;
    return foo46_helper1_c36(l);
}