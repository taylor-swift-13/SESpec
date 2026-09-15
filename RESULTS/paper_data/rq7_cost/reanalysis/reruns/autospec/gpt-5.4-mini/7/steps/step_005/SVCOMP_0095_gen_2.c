int mult(int n, int m);

/*@
requires m >= 0;
requires n <= INT_MAX / (m == 0 ? 1 : m);
requires n >= INT_MIN / (m == 0 ? 1 : m);
ensures \result == n * m;
assigns \nothing;
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
