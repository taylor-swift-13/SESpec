#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
const char * foo285(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int count = 0;
       
  /*@ Inv
    (count >= 0) &&
    (1 <= i) &&
    (count <= i - 1)
    */
for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                count++;
            }
        }
        if (count % 2 == 0) {
            return "Even";
        } else {
            return "Odd";
        }
}