#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_divisors : Z -> Z -> Z -> Z) */
const char * foo285(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int count = 0;
       
  /*@ Inv
    (1 <= i) &&
    (0 <= count) &&
    (count <= i - 1) &&
    (n == n@pre) &&
    (count == count_divisors(n, 1, i)) &&
    (forall (k:Z), 1 <= k && k < i && k <= n => (n % k == 0 => count_divisors(n, 1, k + 1) == count_divisors(n, 1, k) + 1)) &&
    (forall (k:Z), 1 <= k && k < i && k <= n => (n % k != 0 => count_divisors(n, 1, k + 1) == count_divisors(n, 1, k))) &&
    ((i <= n@pre) => (count >= 0 && count <= n@pre)) &&
    ((i <= n@pre) => (count == count_divisors(n, 1, i))) &&
    ((i > n@pre) => (count == count_divisors(n, 1, n@pre + 1)))
    */
for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                count++;
            }
        }
        if (count % 2 == 0) {
            return "Even";
        } else {
            return "Odd";
        }
}