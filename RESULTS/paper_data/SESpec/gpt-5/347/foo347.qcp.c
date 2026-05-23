#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo347(int x, int y) 
/*@

Require emp
Ensure Results(__return)
*/{

        if (y < 0) {
            y = -y;
        }
        int count = 0;
       
  /*@ Inv
    (1 <= i && i <= y + 1) &&
    (y >= 0) &&
    (y == (y@pre >= 0 ? y@pre : -y@pre)) &&
    (x == x@pre) &&
    (forall (k:Z), 1 <= k && k < i => k <= y) &&
    (0 <= count) &&
    (count <= i - 1) &&
    ((count == 0) || (exists (k:Z), 1 <= k && k < i && x % k == 0))
    */
for (int i = 1; i <= y; i++) {
            if (x % i == 0) {
                count = count + 1;
            }
        }
        return count;
}