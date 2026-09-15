#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo32_helper1_c8(int n, int m);
int foo32_helper2_c8(int n, int m);
int foo32_helper3_c8(int n);
int foo32_c8(int n, int m);

int foo32_helper2_c8(int n, int m) /*@

Require emp
Ensure Results(__return)
*/
{

    if (m < 0) {
      return foo32_helper2_c8(n, -m);
    }
    if (n < 0) {
      return foo32_helper2_c8(-n, m); // 0
    }
    if (m == 0) {
      return 0; // 0
    }
    if (n == 0) {
      return 1; // 1
    }
    return foo32_helper2_c8(n - m, m);
}

int foo32_c8(int n, int m) 
{

    if (n <= 1) {
      return 0; // 0
    } else if (n == 2) {
      return 1; // 1
    } else {
      if (m <= 1) {
        return 1; // 1
      } else {
        if (foo32_helper2_c8(n, m) == 0) {
          return 0; // 0
        }
        return foo32_c8(n, m - 1);
      }
    }
}

int foo32_c8(int n, int m) 
/*@

Require emp
Ensure Results(__return)
*/{

    if (n <= 1) {
      return 0; // 0
    } else if (n == 2) {
      return 1; // 1
    } else {
      if (m <= 1) {
        return 1; // 1
      } else {
        if (foo32_helper2_c8(n, m) == 0) {
          return 0; // 0
        }
        return foo32_c8(n, m - 1);
      }
    }
}