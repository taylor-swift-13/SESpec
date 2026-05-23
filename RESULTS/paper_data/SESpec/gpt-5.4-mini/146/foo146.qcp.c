#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo146(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        if(n <= 0) {
            return 0;
        }
       
  /*@ Inv
    (1 <= n) &&
    (n % 4 == 0 => n % 2 == 0) &&
    (n % 4 == 0 => n > 0) &&
    (n >= 1) &&
    (n % 4 == 0 || n % 4 == 1 || n % 4 == 2 || n % 4 == 3) &&
    ((n % 4 == 0) => (n == 4 * (n / 4))) &&
    ((n % 4 == 0) => (n % 2 == 0))
    */
while (n % 4 == 0) {
            n /= 4;
        }
        return n == 1;
}