
/*@
  requires n >= 0;
  requires q > 0;
  requires p >= 0;
  ensures \result == (p * (10^n)) / q;
*/

int foo389(int p, int q, int n) {

    int res = 0;

    /*@
      loop invariant n >= 0;
      loop invariant p >= 0;
      loop invariant q > 0;
      loop invariant n <= \at(n, Pre);
      loop invariant (\at(n, Pre) > 0) ==> (p >= 0);
      loop invariant (\at(n, Pre) > 0) ==> (n >= 0);
      loop invariant (!(\at(n, Pre) > 0)) ==> ((res == 0) && (n == \at(n, Pre)) && (q == \at(q, Pre)) && (p == \at(p, Pre)));
      loop invariant q == \at(q, Pre);
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
