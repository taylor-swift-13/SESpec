#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <assert.h>

int foo36_helper1_c9(int m, int n, int c);
int foo36_c9(int m, int n);

int foo36_helper1_c9(int m, int n, int c) /*@

Require emp
Ensure Results(__return)
*/
{
    if (n == 0) return m;
    if (c >= 150) assert(0);
    if (n > 0) return foo36_helper1_c9(m + 1, n - 1, c + 1);
    return foo36_helper1_c9(m - 1, n + 1, c + 1);
}

int foo36_c9(int m, int n) 
/*@

Require emp
Ensure Results(__return)
*/{
    if (m < 0 || m >= 10000) return -1;
    if (n < 0 || n >= 10000) return -1;
    int result = foo36_helper1_c9(m, n, 0);
    return result == m + n;
}