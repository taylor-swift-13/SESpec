#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (fact_of : Z -> Z) */
int foo327(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int fact = 1;
       
  /*@ Inv
    (2 <= i && i <= n@pre + 1 || (i == 2 && n@pre < 2)) &&
    (fact >= 1) &&
    (fact == fact_of(i - 1)) &&
    ((i == n@pre + 1) => (fact == fact_of(n@pre))) &&
    (n == n@pre)
    */
for (int i = 2; i <= n; i++) {
        fact *= i;
    }
        int foo327 = 0;
       
  /*@ Inv
    (0 <= foo327 && foo327 <= 9) &&
    (fact >= 0) &&
    (fact > 0 => (0 <= fact % 10 && fact % 10 <= 9)) &&
    ((fact == 0) => (0 <= foo327 && foo327 <= 9))
    */
while (fact > 0) {
        foo327 = fact % 10;
        fact /= 10;
    }
        return foo327;
}