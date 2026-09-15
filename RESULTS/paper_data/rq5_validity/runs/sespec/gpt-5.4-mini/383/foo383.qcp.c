#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (divcount : Z -> Z -> Z) */
int foo383(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int count = 0;
       
  /*@ Inv
    (1 <= i && i <= n + 1) &&
    (0 <= count && count <= i - 1) &&
    (count == divcount(n, i)) &&
    (count == divcount(n@pre, i)) &&
    (forall (k:Z), 1 <= k && k < i => ((n % k) == 0 => divcount(n, k + 1) == divcount(n, k) + 1)) &&
    (forall (k:Z), 1 <= k && k < i && (n % k) == 0 => count >= 1) &&
    ((i <= n@pre) => (count == divcount(n, i))) &&
    ((i <= n@pre) => (0 <= count && count <= i - 1)) &&
    (n == n@pre)
    */
for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                count++;
            }
        }
        return count;
}