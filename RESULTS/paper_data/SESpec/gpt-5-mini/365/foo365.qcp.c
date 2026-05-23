#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo365(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int sum = 0;
        int count = 0;
       
  /*@ Inv
    (1 <= i && i <= n + 1) &&
    (0 <= sum) &&
    (0 <= count) &&
    (0 <= i - 1 && i - 1 <= n) &&
    (count <= i - 1) &&
    (sum >= count) &&
    (sum <= (i - 1) * i / 2) &&
    (forall (k:Z), 1 <= k && k < i => (k % 2 != 0 => k <= sum)) &&
    ((count > 0) => (exists (k:Z), 1 <= k && k < i && k % 2 != 0)) &&
    ((i <= n@pre) => (0 <= sum && sum <= (i - 1) * i / 2)) &&
    ((i <= n@pre) => (0 <= count && count <= i - 1)) &&
    (n == n@pre)
    */
for (int i = 1; i <= n; i++) {
        if (i % 2 != 0) {
            sum += i;
            count++;
        }
    }
        return sum / count;
}