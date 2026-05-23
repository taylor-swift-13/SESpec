#include <limits.h>

/*@ logic integer nb_divisors(integer x, integer n) =
    n <= 0 ? 0 : nb_divisors(x, n - 1) + (x % n == 0 ? 1 : 0); */

/*@ assigns \nothing;
  ensures \old(y) >= 0 ==> \result == nb_divisors(x, \old(y));
  ensures \old(y) < 0 ==> \result == nb_divisors(x, -\old(y));
  ensures \result >= 0;
  ensures \result <= (\old(y) < 0 ? -\old(y) : \old(y)); */
int stub_A(int x, int y);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int x, int y);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int x, int y) {
    return stub_A(x, y);
}

/*@ assigns \nothing;
  ensures \old(y) >= 0 ==> \result == nb_divisors(x, \old(y));
  ensures \old(y) < 0 ==> \result == nb_divisors(x, -\old(y));
  ensures \result >= 0;
  ensures \result <= (\old(y) < 0 ? -\old(y) : \old(y)); */
int check_B_implies_A(int x, int y) {
    return stub_B(x, y);
}
