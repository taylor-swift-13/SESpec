#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo381(int x, int y) 
/*@

Require emp
Ensure Results(__return)
*/{

        int count = 0;
       
  /*@ Inv
    ((i <= x@pre && i <= y@pre) => (i >= 1)) &&
    ((i <= x@pre && i <= y@pre) => (i <= x@pre && i <= y@pre)) &&
    (0 <= count) &&
    ((i <= x@pre && i <= y@pre) => (count <= i - 1)) &&
    (forall (k:Z), 1 <= k && k < i => ((x@pre % k == 0 && y@pre % k == 0) => count >= 1 || i == 1)) &&
    (forall (k:Z), 1 <= k && k < i => ((x@pre % k != 0 || y@pre % k != 0) || count <= i - 1)) &&
    (forall (k:Z), 1 <= k && k < i && (x@pre % k == 0 && y@pre % k == 0) => 1 <= count) &&
    ((i == 1) => (count == 0)) &&
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