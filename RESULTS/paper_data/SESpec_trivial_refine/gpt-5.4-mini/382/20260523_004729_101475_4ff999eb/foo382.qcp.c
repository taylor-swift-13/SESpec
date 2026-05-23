#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (is_match : Z -> Z -> Z -> Prop) */
int foo382(int n, int x, int y) 
/*@

Require emp
Ensure Results(__return)
*/{

        int max = 0;
       
  /*@ Inv
    (max < i) &&
    (max == 0 || is_match(max, x, y)) &&
    (forall (k:Z), 1 <= k && k < i => (is_match(k, x, y) => k <= max))
    */
for (int i = 1; i <= n; i++) {
            if ((i % x) == y) {
                max = i;
            }
        }
        return max;
}