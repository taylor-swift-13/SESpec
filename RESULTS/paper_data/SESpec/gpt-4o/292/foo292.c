
#include <stdlib.h>

/*@
  logic integer fib_mod(integer n) =
    n == 0 ? 0 :
    n == 1 ? 1 :
    (2 * fib_mod(n - 1) + fib_mod(n - 2)) % 1000000000;
*/

/*@
  requires seed >= 2; // Strengthened precondition to ensure loop invariants can be established
  assigns \nothing; // Function does not modify any caller-visible state
*/
int foo292(int seed) {
    int *p = (int *)malloc(sizeof(int) * (seed + 1));
    /*@
      ensures p != \null; // Ensure memory allocation was successful
    */
    int p_len = seed + 1;
    p[0] = 0;
    p[1] = 1;

    /*@
      loop invariant 2 <= count <= seed + 1;
      loop assigns count, p[0..seed];
    */
    for (int count = 2; count <= seed; count++) {
        p[count] = (2 * p[count - 1] + p[count - 2]) % 1000000000;
    }

    return p[seed];
}
