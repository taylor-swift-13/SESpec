int mult(int n, int m);

/*@
    requires m >= 0;
    assigns \nothing;
    ensures \result == n * m;
    decreases m;
*/
int mult(int n, int m) {

    if (m < 0) {
      return mult(n, -m);
    }
    if (m == 0) {
      return 0;
    }
    return n + mult(n, m - 1);
}
