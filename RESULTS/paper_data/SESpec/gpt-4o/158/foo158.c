
#include <stdlib.h>

/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  predicate valid_factors(int* factors, integer n) =
    \forall integer k; 0 <= k < n ==> factors[k] == k + 1;
*/
/*@
  requires n >= 0;
  assigns \result, i, factors[0..n-1];
  ensures n <= 2 ==> \result == n;
  ensures n > 2 ==> \result % \old(n) == 0;
  ensures n > 2 ==> \forall integer k; 0 <= k < n ==> \result % (k + 1) == 0;
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
      loop invariant valid_factors(factors, j);
      loop assigns j, factors[0..n-1];
      loop variant n - j;
    */
    for (int j = 0; j < n; j++) {
        factors[j] = j + 1;
    }

    /*@
      loop invariant valid_factors(factors, n);
      loop assigns i;
    */
    while (1) {
        /*@
          loop invariant 0 <= a <= n;
          loop invariant valid_factors(factors, n);
          loop assigns a, i;
          loop variant n - a;
        */
        for (int a = 0; a < n; a++) {
            if (i % factors[a] != 0) {
                i += n;
                break;
            }
            if (factors[a] == factors[n - 1] && i % factors[a] == 0) {
                /*@
                  ensures \result == i;
                  ensures \result % \old(n) == 0;
                  ensures \forall integer k; 0 <= k < n ==> \result % (k + 1) == 0;
                */
                return i;
            }
        }
    }
}
