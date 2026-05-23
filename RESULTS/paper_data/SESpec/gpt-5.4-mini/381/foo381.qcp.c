#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (common_divisor_count : Z -> Z -> Z -> Z) */
int foo381(int x, int y) 
/*@

Require emp
Ensure Results(__return)
*/{

        int count = 0;
       
  /*@ Inv
    (1 <= i) &&
    (count >= 0) &&
    (count <= i - 1) &&
    (count == common_divisor_count(x@pre, y@pre, i - 1)) &&
    (y == y@pre) &&
    (x == x@pre)
    */
for (int i = 1; i <= x && i <= y; i++) {
            if (x % i == 0 && y % i == 0) {
                count++;
            }
        }
        return count;
}