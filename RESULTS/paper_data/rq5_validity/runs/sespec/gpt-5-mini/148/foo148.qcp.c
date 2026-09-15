#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo148(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        if(n <= 0) {
            return 0;
        }
       
  /*@ Inv
    (1 <= n) &&
    (n % 2 == 0 || n % 2 == 1) &&
    (n == 1 || n/2 < n) &&
    (n % 2 == 0 => n >= 2)
    */
while (n % 2 == 0) {
        n /= 2;
    }
        return n == 1;
}