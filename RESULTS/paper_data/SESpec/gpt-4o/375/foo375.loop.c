
/*@
  logic integer factorial(integer n) =
    n <= 0 ? 1 : n * factorial(n - 1);
*/

/*@
  logic integer combination(integer n, integer k) =
    k > n ? 0 : factorial(n) / (factorial(k) * factorial(n - k));
*/

/*@
  requires num >= 0;
  requires 0 <= p <= num;
  ensures \result == combination(num, p);
*/
int foo375(int num, int p) {

    if (p > num - p)
        p = num - p;
    int b = 1;

    /*@
      loop invariant 1 <= r <= p + 1;
      loop invariant p == (\at(p,Pre) > \at(num,Pre) - \at(p,Pre) ? \at(num,Pre) - \at(p,Pre) : \at(p,Pre));
      loop invariant num == \at(num,Pre);
      loop assigns r, b;
    */
    for (int r = 1; r <= p; r++) {
        b = b * (num - r + 1) / r;
    }

    return b;
}
