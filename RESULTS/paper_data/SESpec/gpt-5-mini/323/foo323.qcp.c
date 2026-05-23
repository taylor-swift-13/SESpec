#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (divisors_count_prefix : Z -> Z -> Z) */
int foo323(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int count = 0;
        if (n == 1) return 1;
       
  /*@ Inv
    (2 <= i) &&
    (0 <= count && count <= i - 2) &&
    (count == divisors_count_prefix(n, i)) &&
    ((i <= n / i) => (count >= 0)) &&
    ((!(i <= n / i)) => (i > n / i))
    */
for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            count++;
            if (n / i == i) {
                break;
            }
        }
    }
        return count;
}