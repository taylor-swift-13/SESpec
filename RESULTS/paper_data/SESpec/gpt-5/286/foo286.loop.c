
/*@ 
  logic integer fib2(integer n) =
    n <= 0 ? 0 :
    n == 1 ? 1 :
    fib2(n - 1) + 2 * fib2(n - 2);
*/

#include <stdlib.h>

int foo286(int j) {

    int *r = (int *)malloc(sizeof(int) * (j + 1));
    int r_len = j + 1;
    r[0] = 0;
    r[1] = 1;

    /*@ 
      loop invariant r_len == j + 1;
      loop invariant 2 <= p ==> 0 <= 2 && 2 <= p;
      loop invariant \forall integer k; 0 <= k < 2 ==> r[k] == fib2(k);
      loop invariant \forall integer k; 0 <= k < p ==> r[k] == fib2(k);
      loop invariant \forall integer k; 1 <= k < p ==> r[k] >= r[k-1];
      loop invariant j < 2 ==> (\forall integer k; 0 <= k <= j ==> r[k] == fib2(k));
      loop assigns r[0..j];
    */
    for (int p = 2; p <= j; p++) {
        r[p] = r[p - 1]
                + 2 * r[p - 2];
    }

    return r[j];
}
