
#include <stdlib.h>

/*@
  logic integer pow2(integer n) =
    n <= 0 ? 1 : 2 * pow2(n - 1);
*/

/*@
  logic integer closed_j(integer p) =
    (pow2(p) - ((p % 2 == 0) ? 1 : -1)) / 3;
*/

/*@
  requires c >= 1;
  assigns \nothing;
*/
int foo287(int c) {

    int *j = (int *)malloc(sizeof(int) * (c + 1));
    int j_len = c + 1;
    j[0] = 0;
    j[1] = 1;

    /*@
      loop invariant j_len == c + 1;
      loop invariant j[0] == closed_j(0);
      loop invariant j[1] == closed_j(1);
      loop assigns p, j[0..c];
      loop variant c - p;
    */
    for (int p = 2; p <= c; p++) {
        j[p] = j[p - 1]
             + 2 * j[p - 2];
        /*@ assert j[p] == closed_j(p); */
    }

    return j[c];
}
