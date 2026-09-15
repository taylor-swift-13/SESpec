
#include <limits.h>

/*@
  logic integer prod_nk(integer n, integer t) =
    t <= 0 ? 1 : (n - t + 1) * prod_nk(n, t - 1);
*/

int foo390(int n, int k) {

  int res = 1;
  int i = 1;

  /*@
    loop invariant (1 <= \at(k,Pre)) ==> (1 <= i);
    loop invariant (1 <= \at(k,Pre)) ==> (i <= k + 1);
    loop invariant (1 <= \at(k,Pre)) ==> (0 <= i - 1);
    loop invariant (1 <= \at(k,Pre)) ==> (i - 1 <= k);

    loop invariant (1 <= \at(k,Pre)) ==> (res == prod_nk(n, i - 1));
    loop invariant (1 <= \at(k,Pre)) ==> ((i > k) ==> (res == prod_nk(n, k)));
    loop invariant (1 <= \at(k,Pre)) ==> ((!(i <= k)) ==> (i == k + 1));

    loop invariant (1 <= \at(k,Pre)) ==> ((i > k) ==> (res == prod_nk(n, k)));
    loop invariant (1 <= \at(k,Pre)) ==> (res == prod_nk(n, i - 1));
    loop invariant (1 <= \at(k,Pre)) ==> ((1 <= i) && (i <= k + 1));
    loop invariant (!(1 <= \at(k,Pre))) ==> ((i == 1)&&(res == 1)&&(k == \at(k,Pre))&&(n == \at(n,Pre)));
    loop invariant k == \at(k,Pre);
    loop invariant n == \at(n,Pre);
    loop assigns res, i;
  */
  while (i <= k) {
    res *= (n - i + 1);
    i++;
  }

  return res;
}
