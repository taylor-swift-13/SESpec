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
    (n == n@pre)
    */
for (int i = 2; i <= n; i++) {
        fact *= i;
    }
        int foo327 = 0;
       
  /*@ Inv
    (foo327 >= 0) &&
    (n == n@pre) &&
    (forall (k:Z), 0 <= k && k < foo327 => (k >= 0 && k <= 9))
    */
while (fact > 0) {
        foo327 = fact % 10;
        fact /= 10;
    }
        return foo327;
}