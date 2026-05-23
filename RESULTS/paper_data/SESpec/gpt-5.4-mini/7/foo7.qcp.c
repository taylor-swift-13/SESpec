#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo7(int n, int m);

int foo7(int n, int m) 
{

    if (m < 0) {
      return foo7(n, -m);
    }
    if (m == 0) {
      return 0;
    }
    return n + foo7(n, m - 1);
}

int foo7(int n, int m) 
/*@

Require emp
Ensure Results(__return)
*/{

    if (m < 0) {
      return foo7(n, -m);
    }
    if (m == 0) {
      return 0;
    }
    return n + foo7(n, m - 1);
}