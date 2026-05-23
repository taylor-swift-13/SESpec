
/*@ logic integer foo389_r(integer p, integer q, integer n) =
      n <= 0 ? 0 :
      n == 1 ? (p * 10) / q :
      foo389_r((p * 10) % q, q, n - 1); */

/*@ logic integer foo389_p(integer p, integer q, integer n) =
      n <= 0 ? p :
      foo389_p((p * 10) % q, q, n - 1); */

/*@
  requires q > 0;
  requires n >= 0;
  assigns \nothing;
*/
int foo389(int p, int q, int n)
{
    int res = 0;
    /*@ ghost int p0 = p; */
    /*@ ghost int n0 = n; */
    /*@ ghost int k = 0; */

    /*@
      loop invariant 0 <= n <= n0;
      loop invariant k == n0 - n;
      loop invariant q > 0;
      loop assigns n, p, res, k;
      loop variant n;
    */
    while (n > 0) {
        n -= 1;
        p *= 10;
        res = p / q;
        p %= q;
        /*@ ghost k += 1; */
    }

    return res;
}
