
/*@ predicate divides(integer d, integer n) = \exists integer k; n == d * k; */

/*@ predicate gcd_is(integer g, integer a, integer b) =
      g > 0 &&
      divides(g, a) &&
      divides(g, b) &&
      \forall integer k; 1 <= k && divides(k, a) && divides(k, b) ==> k <= g;
*/

/*@ 
  assigns \nothing;
  ensures \true;
*/
int foo322(int x, int y) {

  int gcd = 1;
  int foo322 = 1;

  if (x > y) {
    int temp = x;
    x = y;
    y = temp;
  }

  /*@
    loop invariant 1 <= i;
    loop invariant 1 <= gcd;
    loop assigns i, gcd;
  */
  for (int i = 1; i <= x; i++) {
    if (x % i == 0 && y % i == 0) {
      gcd = i;
    }
  }

  foo322 = (x * y) / gcd;
  return foo322;
}
