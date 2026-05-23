
#include <stdlib.h>

/*@
  predicate rec_ok(int* div, integer k, integer m, integer w) =
    (k == 0 ==> div[0] == 1) &&
    (k == 1 ==> div[1] == m) &&
    (k == 2 ==> div[2] == m * m) &&
    (k >= 3 ==> div[k] == ((m - 1) * (div[k - 1] + div[k - 2])) % w);
*/

int foo147(int count, int m) {

    int w = 1000000007;
    int *div = (int *)malloc(sizeof(int) * (count + 1));
    int div_len = count + 1;
    div[0] = 1;
    div[1] = m;
    div[2] = m * m;

    /*@
      loop invariant 3 <= d;
      loop invariant (d <= count) ==> 3 <= d && d <= count;
      loop invariant div_len == count + 1;
      loop invariant div[0] == 1 && div[1] == m && div[2] == m * m;
      loop invariant \forall integer k; 3 <= k < d ==> div[k] == ((m - 1) * (div[k - 1] + div[k - 2])) % w;
      loop assigns d, div[0 .. div_len - 1];
    */
    for (int d = 3; d <= count; d++) {
        div[d] = ((m - 1)
                * (div[d - 1] + div[d - 2])) % w;
    }

    return div[count];
}
