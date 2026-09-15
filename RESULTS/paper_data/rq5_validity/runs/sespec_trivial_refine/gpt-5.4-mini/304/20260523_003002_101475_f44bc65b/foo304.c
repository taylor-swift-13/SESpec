
#include <stdlib.h>

/*@ logic integer pell304(integer n) =
      n == 0 ? 0 :
      n == 1 ? 1 :
      (2 * pell304(n - 1) + pell304(n - 2)) % 1000000000; */
/*@
  requires n >= 1;
  assigns \nothing;
  ensures \result == pell304(n);
  ensures 0 <= \result < 1000000000;
  ensures n == 1 ==> \result == 1;
  ensures n > 1 ==> \result == ((2 * pell304(n - 1) + pell304(n - 2)) % 1000000000);
*/
int foo304(int n) {
    int i;
    int p0 = 0;
    int p1 = 1;
    int p2 = 1;

    if (n == 1) {
        return 1;
    }

    /*@
      loop invariant 2 <= i <= n + 1;
      loop invariant p0 == pell304(i - 2);
      loop invariant p1 == pell304(i - 1);
      loop invariant p2 == pell304(i - 1);
      loop invariant 0 <= p0 < 1000000000;
      loop invariant 0 <= p1 < 1000000000;
      loop invariant 0 <= p2 < 1000000000;
      loop assigns i, p0, p1, p2;
      loop variant n - i + 1;
    */
    for (i = 2; i <= n; i++) {
        p2 = (2 * p1 + p0) % 1000000000;
        p0 = p1;
        p1 = p2;
    }

    return p1;
}
