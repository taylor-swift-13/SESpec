// Integer square root via incrementing counter. The loop invariant
// `r * r <= n` is what carries the lower bound; the upper bound
// follows from the negated loop condition at exit.

/*@
  requires n >= 0;
  ensures \result >= 0;
  ensures \result * \result <= n;
  ensures (\result + 1) * (\result + 1) > n;
*/
int integer_sqrt(int n) {
    int r = 0;
    /*@
      loop invariant 0 <= r;
      loop invariant r * r <= n;
      loop assigns r;
      loop variant n - r * r;
    */
    while ((r + 1) * (r + 1) <= n) {
        r++;
    }
    return r;
}
