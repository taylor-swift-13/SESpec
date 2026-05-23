
/*@
  logic integer power10(integer k) =
    k <= 0 ? 1 : 10 * power10(k-1);
*/

/*@
  requires \true;
*/
int unknown();

/*@
  requires \true;
  requires q > 0;
  requires n >= 0;
  requires 0 <= p && p < q;
  assigns \nothing;
*/
int foo389(int p, int q, int n) {

    int res = 0;

    /*@
      loop invariant q == \at(q,Pre);
      loop invariant 0 <= n && n <= \at(n,Pre);
      loop invariant 0 <= res;
      loop invariant 0 <= p && p < \at(q,Pre);
      loop invariant (\at(p,Pre) * power10(\at(n,Pre) - n)) * 10 == (\at(p,Pre) * power10(\at(n,Pre) - (n - 1)));
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
