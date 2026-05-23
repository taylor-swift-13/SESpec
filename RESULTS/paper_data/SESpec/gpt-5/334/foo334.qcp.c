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
    (n == n@pre) &&
    (sum1 == 0) &&
    (sum >= 0) &&
    (i >= 1) &&
    ((i == 1) => (sum == 0)) &&
    (forall (k:Z), 1 <= k && k < i => (k*k*k >= 0)) &&
    ((i <= n) => (sum + i*i*i >= sum))
    */
for (int i = 1; i <= n; i++) {
            sum += i * i * i;
        }
       
  /*@ Inv
    (1 <= i) &&
    (n == n@pre) &&
    (sum1 >= 0) &&
    ((i == 1) => (sum1 == 0)) &&
    (forall (k:Z), 1 <= k && k < i => (k >= 1)) &&
    ((i <= n) => (sum1 + i >= sum1))
    */
for (int i = 1; i <= n; i++) {
            sum1 += i;
        }
        return sum - sum1;
}