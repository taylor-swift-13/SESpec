
#include <stdlib.h>

/*@
  logic integer seq_ret(integer k) =
    k == 0 ? 0
    : k == 1 ? 1
    : seq_ret(k-1) + 2*seq_ret(k-2);
*/

/*@
  requires j >= 1;
  assigns \nothing;
  ensures \result == seq_ret(j);
*/
int foo288(int j) {

    int *ret = (int *)malloc(sizeof(int) * (j + 1));
    int ret_len = j + 1;
    ret[0] = 0;
    ret[1] = 1;

    /*@
      loop invariant 2 <= j + 1;
      loop invariant ret_len == j + 1;
      loop invariant ret_len >= 2;
      loop invariant 2 <= p <= j + 1;
      loop invariant ret[0] == seq_ret(0);
      loop invariant ret[1] == seq_ret(1);
      loop assigns p, ret[0..j];
    */
    for (int p = 2; p <= j; p++) {
        ret[p] = ret[p - 1]
                + 2 * ret[p - 2];
    }

    return ret[j];
}
