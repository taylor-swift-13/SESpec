
/*@
  logic integer gcd(integer a, integer b) =
    b == 0 ? a : gcd(b, a % b);
*/

/*@
  requires n > 0 && y > 0;
  requires gcd(n, y) > 0; // Strengthened precondition: GCD computation must be valid.
  ensures \result > 0;
  assigns \nothing;
*/
int foo321(int n, int y) {

    int ret = 1;
    int r = 1;
    if (n > y) {
        int g = n;
        n = y;
        y = g;
    }

    /*@
      loop invariant 1 <= l <= n + 1;
      loop invariant ret >= 1;
      loop invariant ret <= l;
      loop invariant ret <= n;
      loop invariant ret <= y;
      loop invariant (n % ret == 0) && (y % ret == 0);
      loop invariant \forall integer k; 1 <= k < l ==> ((n % k == 0) && (y % k == 0)) ==> k <= ret;
      loop assigns l, ret;
      loop variant n - l;
    */
    for (int l = 1; l <= n; l++) {
        if (n % l == 0 && y % l == 0) {
            ret = l;
        }
    }

    r = (n * y) / ret;

    /*@
      ensures r == (n * y) / ret;
      ensures r > 0;
      ensures r % n == 0 && r % y == 0;
      ensures \forall integer k; k > 0 && k <= r ==> (k % n == 0 && k % y == 0) ==> k == r;
    */
    return r;
}
