#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo383(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int count = 0;
       
  /*@ Inv
    (n == n@pre) &&
    (0 <= count && count <= i - 1) &&
    (forall (k:Z), 1 <= k && k < i => (n % k == 0) => 1 <= k && k <= n@pre) &&
    (forall (k:Z), 1 <= k && k < i => (n % k != 0) || (n % k == 0)) &&
    (forall (k:Z), 1 <= k && k < i => (n % k == 0) => 1 <= k) &&
    (forall (k:Z), 1 <= k && k < i => (n % k != 0) => count == count) &&
    (forall (k:Z), 1 <= k && k < i => (n % k == 0) => count >= 1 || i == 1) &&
    (forall (k:Z), 1 <= k && k < i => (n % k == 0) => exists (t:Z), 1 <= t && t < i && n % t == 0) &&
    ((i <= n@pre) => (0 <= count && count <= i)) &&
    ((i <= n@pre) => (0 <= count && count <= n@pre)) &&
    (forall (k:Z), 1 <= k && k < i => (n % k == 0) => count >= 1 || i == 1) &&
    (forall (k:Z), 1 <= k && k < i => (n % k != 0) => 0 <= count)
    */
for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                count++;
            }
        }
        return count;
}