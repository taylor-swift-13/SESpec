
#include <stdlib.h>

/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires n >= 0;
  ensures \result == n || \result == n * 2;
*/
int foo158(int n) {

    if (n <= 2) {
        return n;
    }
    int i = n * 2;
    int *factors = (int *)malloc(sizeof(int) * (n));
    int factors_len = n;

    /*@
      loop invariant 0 <= j <= n;
      loop invariant \forall integer k; 0 <= k < j ==> factors[k] == k + 1;
      loop assigns j, factors[0..n-1];
    */
    for (int j = 0; j < n; j++) {
        factors[j] = j + 1;
    }

    /*@
      loop invariant \forall integer k; 0 <= k < n ==> factors[k] == k + 1;
      loop assigns i;
    */
    while (1) {
        /*@
          loop invariant 0 <= a <= n;
          loop invariant \forall integer k; 0 <= k < n ==> factors[k] == k + 1;
          loop assigns a, i;
        */
        for (int a = 0; a < n; a++) {
            if (i % factors[a] != 0) {
                i += n;
                break;
            }
            if (factors[a] == factors[n - 1] && i % factors[a] == 0) {
                return i;
            }
        }
    }
}
