// Iterative power computation. Uses a helper logic function `power`
// defined recursively so the invariant `result == power(base, e)` can
// track the partial product across iterations.

/*@
  logic integer power(integer base, integer exp) =
    exp <= 0 ? 1 : base * power(base, exp - 1);
*/

/*@
  requires base >= 0;
  requires exp >= 0;
  ensures \result == power(base, exp);
*/
int power(int base, int exp) {
    int result = 1;
    int e = 0;
    /*@
      loop invariant 0 <= e <= exp;
      loop invariant result == power(base, e);
      loop assigns e, result;
      loop variant exp - e;
    */
    while (e < exp) {
        result *= base;
        e++;
    }
    return result;
}
