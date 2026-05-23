
#include <stdlib.h>

/*@
  logic integer fib_like(int j) =
    j == 0 ? 0 :
    j == 1 ? 1 :
    fib_like((int)(j - 1)) + 2 * fib_like((int)(j - 2));
*/

/*@
  requires j >= 0;
  ensures \result == fib_like(j);
*/
int foo286(int j) {
    int *r = (int *)malloc(sizeof(int) * (j + 1));
    int r_len = j + 1;
    r[0] = 0;
    r[1] = 1;

    /*@
      loop assigns p, r[0..j];
    */
    for (int p = 2; p <= j; p++) {
        r[p] = r[p - 1] + 2 * r[p - 2];
    }

    return r[j];
}
