#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (nb_divisors : Z -> Z -> Z) */
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
    (0 <= count && count <= i - 1) &&
    (count == nb_divisors(x, i - 1)) &&
    (forall (k:Z), 1 <= k && k < i => (x % k == 0 || x % k != 0)) &&
    (y >= 0) &&
    (x == x@pre) &&
    (y == y@pre || y == -y@pre)
    */
for (int i = 1; i <= y; i++) {
            if (x % i == 0) {
                count = count + 1;
            }
        }
        return count;
}