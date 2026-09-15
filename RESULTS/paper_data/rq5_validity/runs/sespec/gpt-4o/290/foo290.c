
#include <stdlib.h>

/*@
  logic integer compute_N(int c, integer p) =
    p == 0 ? 2 :
    p == 1 ? 1 :
    compute_N(c, p - 1) + 2 * compute_N(c, p - 2);
*/

/*@
  requires c >= 0;
  assigns \nothing;
  ensures \result == compute_N(c, c);
*/
int foo290(int c) {
    int *N = (int *)malloc(sizeof(int) * (c + 1));
    /*@
      ensures N != \null;
      ensures \valid(N + (0 .. c));
    */
    int N_len = c + 1;
    N[0] = 2;
    N[1] = 1;

    /*@
      loop invariant 2 <= p <= c + 1;
      loop invariant N[0] == 2 && N[1] == 1;
      loop invariant \forall integer k; 2 <= k < p ==> N[k] == compute_N(c, k);
      loop assigns N[2..c], p;
      loop variant c - p;
    */
    for (int p = 2; p <= c; p++) {
        N[p] = N[p - 1] + 2 * N[p - 2];
    }

    /*@
      ensures \result == compute_N(c, c);
    */
    return N[c];
}
