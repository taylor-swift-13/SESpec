#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (cube_sum : Z -> Z) */
int foo334(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int sum = 0;
        int sum1 = 0;
       
  /*@ Inv
    (1 <= i && i <= n + 1) &&
    (0 <= sum) &&
    (sum == cube_sum(i - 1)) &&
    ((forall (k:Z), 1 <= k && k < i => k * k * k >= 0)) &&
    ((i <= n@pre) => (sum == cube_sum(i - 1))) &&
    ((i <= n@pre) => (sum >= 0)) &&
    (sum1 == 0) &&
    (n == n@pre)
    */
for (int i = 1; i <= n; i++) {
            sum += i * i * i;
        }
       
  /*@ Inv
    (1 <= i && i <= n + 1) &&
    (0 <= sum1) &&
    (sum1 == (i > 1 ? ((i - 1) * i) / 2 : 0)) &&
    ((forall (k:Z), 1 <= k && k < i => ((k * (k + 1)) / 2) <= sum1)) &&
    ((i <= n) => (sum1 == (i > 1 ? ((i - 1) * i) / 2 : 0))) &&
    (!(i <= n) => (sum1 == (n * (n + 1)) / 2))
    */
for (int i = 1; i <= n; i++) {
            sum1 += i;
        }
        return sum - sum1;
}