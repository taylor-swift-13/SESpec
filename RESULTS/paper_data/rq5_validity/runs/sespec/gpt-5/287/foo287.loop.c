
#include <stdlib.h>

/*@
  logic integer pow2(integer n) =
    n <= 0 ? 1 : 2 * pow2(n - 1);
*/

/*@
  logic integer closed_j(integer p) =
    (pow2(p) - ((p % 2 == 0) ? 1 : -1)) / 3;
*/

/* We do not modify any provided contracts; only loop invariants are added as requested. */
int foo287(int c) {

    int *j = (int *)malloc(sizeof(int) * (c + 1));
    int j_len = c + 1;
    j[0] = 0;
    j[1] = 1;

    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@
      loop invariant j_len == c + 1;
      loop invariant j[0] == 0;
      loop invariant \exists integer t; 0 <= t < p && j[t] == j[p - 1];
      loop assigns p, j[0..c];
    */
    for (int p = 2; p <= c; p++) {
        j[p] = j[p - 1]
             + 2 * j[p - 2];
    }

    return j[c];
}
