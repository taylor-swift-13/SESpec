// Euclidean GCD via modular reduction. The right invariant is the
// preservation pair `a >= 0 && b >= 0` and `a + b > 0`; together with
// the loop variant `b` they guarantee termination at the true gcd.

/*@
  requires a >= 0 && b >= 0;
  requires a + b > 0;
  ensures \result > 0;
  ensures \exists integer k; \old(a) == k * \result + (\old(a) % \result);
*/
int gcd(int a, int b) {
    /*@
      loop invariant a >= 0 && b >= 0;
      loop invariant a + b > 0;
      loop assigns a, b;
      loop variant b;
    */
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
