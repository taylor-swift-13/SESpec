#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (factorial : Z -> Z) */
int foo327(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int fact = 1;
       
  /*@ Inv
    (2 <= i && i <= n + 1) &&
    (fact == factorial(i - 1)) &&
    (fact >= 1) &&
    ((i <= n) => fact > 0) &&
    ((i > n) => fact == factorial(n)) &&
    (n == n@pre)
    */
for (int i = 2; i <= n; i++) {
            fact *= i;
        }
        int foo327 = 0;
       
  /*@ Inv
    (fact >= 0) &&
    (0 <= foo327 && foo327 <= 9) &&
    ((fact > 0) => 0 <= foo327 && foo327 <= 9) &&
    ((fact == 0) => 0 <= foo327 && foo327 <= 9)
    */
while (fact > 0) {
            foo327 = fact % 10;
            fact /= 10;
        }
        return foo327;
}