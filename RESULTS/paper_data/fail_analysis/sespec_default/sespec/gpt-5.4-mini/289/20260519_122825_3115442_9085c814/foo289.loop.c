
#include <stdlib.h>

/*@
  logic integer poly289(integer n) =
    n == 0 ? 2 :
    n == 1 ? 1 :
    poly289(n - 1) + 2 * poly289(n - 2);
*/

int foo289(int c) {
    int *j = (int *)malloc(sizeof(int) * (c + 1));
    int j_len = c + 1;
    int d;

    j[0] = 2;
    j[1] = 1;

    /*@
      loop invariant j_len == c + 1;
      loop invariant \forall integer k; 2 <= k < d ==> j[k] == j[k - 1] + 2 * j[k - 2];
      loop assigns d, j[0..c];
    */
    for (d = 2; d <= c; d++) {
        j[d] = j[d - 1] + 2 * j[d - 2];
    }

    return j[c];
}
