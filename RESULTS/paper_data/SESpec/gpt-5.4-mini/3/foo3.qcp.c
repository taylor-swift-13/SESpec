#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo3(int y1, int y2);

int foo3(int y1, int y2) 
{

        if (y1 <= 0 || y2 <= 0) {
          return 0;
        }
        if (y1 == y2) {
          return y1;
        }
        if (y1 > y2) {
          return foo3(y1 - y2, y2);
        }
        return foo3(y1, y2 - y1);
}

int foo3(int y1, int y2) 
/*@

Require emp
Ensure Results(__return)
*/{

        if (y1 <= 0 || y2 <= 0) {
          return 0;
        }
        if (y1 == y2) {
          return y1;
        }
        if (y1 > y2) {
          return foo3(y1 - y2, y2);
        }
        return foo3(y1, y2 - y1);
}