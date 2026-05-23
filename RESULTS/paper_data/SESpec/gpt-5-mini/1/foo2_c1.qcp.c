#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo2_c1(int m, int n);

int foo2_c1(int m, int n) 
{

        if (n == 0) {
            return m;
        }
        if (n > 0) {
            return foo2_c1(m + 1, n - 1);
        } else {
            return foo2_c1(m - 1, n + 1);
        }
}

int foo2_c1(int m, int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        if (n == 0) {
            return m;
        }
        if (n > 0) {
            return foo2_c1(m + 1, n - 1);
        } else {
            return foo2_c1(m - 1, n + 1);
        }
}