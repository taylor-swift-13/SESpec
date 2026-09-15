
/*@ 
  logic integer power10(integer n) = 
    (n == 0) ? 1 : 10 * power10(n - 1);
*/
/*@
  requires n >= 0;
  requires q > 0;
  requires p >= 0;
  requires (p * power10(n)) % q == 0; // Ensure divisibility
  assigns \nothing;
  ensures \result >= 0;
*/
int foo389(int p, int q, int n) {

    int res = 0;

    /*@
      loop invariant n >= 0;
      loop invariant p >= 0;
      loop invariant q > 0;
      loop invariant res >= 0;
      loop invariant n <= \at(n, Pre);
      loop invariant q == \at(q, Pre);
      loop assigns n, p, res;
      loop variant n;
    */
    while (n > 0) {
        n -= 1;
        p *= 10;
        res = p / q;
        p %= q;
    }

    return res;
}
