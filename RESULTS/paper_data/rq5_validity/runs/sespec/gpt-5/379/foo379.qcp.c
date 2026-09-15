#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (even_contrib : Z -> Z) */
/*@ Extern Coq (sum_even_range : Z -> Z -> Z) */
int foo379(int l, int r) 
/*@

Require emp
Ensure Results(__return)
*/{

        int sum = 0;
       
  /*@ Inv
    (r == r@pre) &&
    (l == l@pre) &&
    (i >= l) &&
    ((l <= r + 1) => (i <= r + 1)) &&
    (sum == sum_even_range(l, i - 1)) &&
    (forall (k:Z), l <= k && k < i => (k % 2 == 0 => even_contrib(k) == k)) &&
    (forall (k:Z), l <= k && k < i => (k % 2 != 0 => even_contrib(k) == 0))
    */
for (int i = l; i <= r; i++) {
            if (i % 2 == 0) {
                sum += i;
            }
        }
        return sum;
}