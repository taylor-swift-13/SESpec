#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo334(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int sum = 0;
        int sum1 = 0;
       
  /*@ Inv
    (i >= 1) &&
    (4 * sum == (i - 1) * (i - 1) * i * i)
    */
for (int i = 1; i <= n; i++) {
    sum += i * i * i;
  }
       
  /*@ Inv
    (i >= 1) &&
    (sum1 == ((i - 1) * i) / 2)
    */
for (int i = 1; i <= n; i++) {
    sum1 += i;
  }
        return sum - sum1;
}