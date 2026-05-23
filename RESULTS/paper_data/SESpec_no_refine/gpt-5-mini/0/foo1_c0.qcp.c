#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo1_c0(int m, int n);

int foo1_c0(int m, int n) 
{

    if (m == 0) {
      return n + 1;
    }
    if (n == 0) {
      return foo1_c0(m - 1, 1);
    }
    return foo1_c0(m - 1, foo1_c0(m, n - 1));
}

int foo1_c0(int m, int n) 
/*@

Require emp
Ensure Results(__return)
*/{

    if (m == 0) {
      return n + 1;
    }
    if (n == 0) {
      return foo1_c0(m - 1, 1);
    }
    return foo1_c0(m - 1, foo1_c0(m, n - 1));
}