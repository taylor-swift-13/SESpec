#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (fact_logic : Z -> Z) */
int foo327(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int fact = 1;
       
  /*@ Inv
    (fact == fact_logic(i - 1)) &&
    (i >= 2) &&
    ((n < 2) || i <= n + 1)
    */
for (int i = 2; i <= n; i++) {
            fact *= i;
        }
        int foo327 = 0;
       
  /*1*/ 
 /*@ Inv
    (fact >= 0) &&
    (foo327 >= 0 && foo327 <= 9)
    */
while (fact > 0) {
            foo327 = fact % 10;
            fact /= 10;
        }
        return foo327;
}