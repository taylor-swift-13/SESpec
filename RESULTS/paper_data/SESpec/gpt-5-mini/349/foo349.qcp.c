#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (odd_divisor_sum_prefix : Z -> Z -> Z) */
/*@ Extern Coq (odd_divisor_sum : Z -> Z) */
int foo349(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int sum = 0;
       
  /*@ Inv
    (1 <= i && i <= n + 1) &&
    (0 <= sum) &&
    (n == n@pre) &&
    (sum == odd_divisor_sum_prefix(n@pre, i-1)) &&
    (forall (k:Z), 1 <= k && k <= i-1 => ((n@pre % k == 0 && k % 2 != 0) => 1 <= k && k <= i-1)) &&
    ((!(i <= n@pre)) => (sum == odd_divisor_sum(n@pre)))
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