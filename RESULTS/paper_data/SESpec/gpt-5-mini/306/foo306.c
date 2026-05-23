
#include <stdlib.h>

/*@
  logic integer lucas_seq(integer k) =
    k == 0 ? 2
    : k == 1 ? 1
    : lucas_seq(k-1) + lucas_seq(k-2);
*/

/*@
  requires n >= 1;
  assigns \nothing;
*/
int foo306(int n) {

    int *lucas = (int *)malloc(sizeof(int) * (n + 1));
    int lucas_len = n + 1;
    lucas[0] = 2;
    lucas[1] = 1;

    /*@ 
      loop invariant 2 <= i && i <= n+1;
      loop assigns i, lucas[2..n];
    */
    for (int i = 2; i <= n; i++) {
        lucas[i] = lucas[i - 1] + lucas[i - 2];
    }

    return lucas[n];
}
