#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (cubesum : Z -> Z) */

/*@ Extern Coq (tri : Z -> Z) */
int foo334(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int sum = 0;
        int sum1 = 0;
       
  /*@ Inv
    (i >= 1) &&
    (sum == cubesum(i - 1)) &&
    (0 <= sum) &&
    (sum1 == 0) &&
    (n == n@pre) &&
    ((i <= n@pre) => (sum >= sum1)) &&
    ((i <= n@pre) => (sum == cubesum(i - 1) && 0 <= sum))
    */
for (int i = 1; i <= n; i++) {
            sum += i * i * i;
        }
       
  /*@ Inv
    (i >= 1) &&
    (i <= n + 1) &&
    (sum >= 0) &&
    (sum1 == tri(i - 1)) &&
    (0 <= sum1) &&
    (n == n@pre) &&
    ((i <= n) => (sum1 == tri(i - 1) && 0 <= sum1))
    */
for (int i = 1; i <= n; i++) {
            sum1 += i;
        }
        return sum - sum1;
}