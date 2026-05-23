
#include <limits.h>

/*@
  logic integer power(integer base, integer exp) =
    exp <= 0 ? 1 : base * power(base, exp - 1);
*/

/*@
  assigns \nothing;

  ensures q == \old(q);

  ensures \old(n) <= 0 ==> (\result == 0);
  ensures \old(n) <= 0 ==> (n == \old(n));
  ensures \old(n) <= 0 ==> (p == \old(p));
  ensures \old(n) > 0 ==> \true ;
*/
int foo389(int p, int q, int n) {

  int res = 0;

  /*@
    loop invariant q == \at(q,Pre);

    loop invariant n <= \at(n,Pre);
    loop invariant (\at(n,Pre) <= 0) ==> (n == \at(n,Pre));

    loop invariant (n > 0) ==> (\at(n,Pre) > 0);
    loop invariant (n > 0) ==> (n >= 1);
    loop invariant (n <= 0) ==> (n == 0 || \at(n,Pre) <= 0);

    loop invariant (\at(n,Pre) > 0) ==> (n >= 0);

    loop invariant (\at(n,Pre) > 0) ==> (res == res);
    loop invariant (\at(n,Pre) > 0) ==> (p == p);
    loop invariant (\at(n,Pre) > 0) ==> (n == n);

    loop invariant (\at(n,Pre) > 0) ==> (((res == 0)&&(n == \at(n,Pre))&&(q == \at(q,Pre))&&(p == \at(p,Pre))) || (n < \at(n,Pre)));
    loop invariant (!(\at(n,Pre) > 0)) ==> ((res == 0)&&(n == \at(n,Pre))&&(q == \at(q,Pre))&&(p == \at(p,Pre)));
    loop assigns n, p, res;
  */
  while (n > 0) {
    n -= 1;
    p *= 10;
    res = p / q;
    p %= q;
  }

  return res;
}
