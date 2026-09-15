
/*@
  logic integer power10(integer k) =
    k <= 0 ? 1 : 10 * power10(k-1);
*/

/*@
  requires \true;
*/
int unknown();

int foo389(int p, int q, int n) {

    int res = 0;

    /* >>> LOOP INVARIANT TO_FILL <<< */

    /*@
      loop invariant q == \at(q,Pre);
      loop invariant (\at(n,Pre) == n) ==> (p == \at(p,Pre) && res == 0);
          n == \at(n,Pre) - k &&
          p == (\at(p,Pre) * power10(k)) % \at(q,Pre) &&
          res == ((\at(p,Pre) * power10(k)) / \at(q,Pre)));
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
