#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo349(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int sum = 0;
       
  /*@ Inv
    (i >= 1) &&
    (sum >= 0) &&
    (n == n@pre) &&
    ((i <= n@pre) => (sum >= 0)) &&
    ((!(i <= n@pre)) => (sum >= 0))
    */
for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                if (i % 2 != 0) {
                    sum += i;
                }
            }
        }
        return sum;
}