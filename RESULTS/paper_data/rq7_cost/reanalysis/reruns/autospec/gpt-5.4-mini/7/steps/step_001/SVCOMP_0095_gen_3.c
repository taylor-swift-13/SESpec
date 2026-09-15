int mult(int n, int m);

/*@
requires m >= 0;
requires n <= INT_MAX;
requires n >= INT_MIN;
requires m == 0 || mult(n, m - 1) <= INT_MAX - n;
requires m == 0 || mult(n, m - 1) >= INT_MIN - n;
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
