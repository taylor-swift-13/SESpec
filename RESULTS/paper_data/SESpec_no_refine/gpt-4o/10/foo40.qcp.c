#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo40(int i);

int foo40(int i) 
{

    if (i == 0) {
      return 1;
    }
    if (i > 0) {
      return foo40(i - 1);
    }
    if (i < 0) {
      return 0;
    }
    return 1;
}

int foo40(int i) 
/*@

Require emp
Ensure Results(__return)
*/{

    if (i == 0) {
      return 1;
    }
    if (i > 0) {
      return foo40(i - 1);
    }
    if (i < 0) {
      return 0;
    }
    return 1;
}