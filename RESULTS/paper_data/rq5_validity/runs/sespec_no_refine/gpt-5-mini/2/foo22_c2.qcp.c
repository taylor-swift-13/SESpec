#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo22_c2(int n);

int foo22_c2(int n) 
{

        if (n < 1) {
          return 0;
        } else if (n == 1) {
          return 1;
        } else {
          return foo22_c2(n - 1) + foo22_c2(n - 2);
        }
}

int foo22_c2(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        if (n < 1) {
          return 0;
        } else if (n == 1) {
          return 1;
        } else {
          return foo22_c2(n - 1) + foo22_c2(n - 2);
        }
}