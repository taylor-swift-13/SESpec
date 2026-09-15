int mult(int n, int m);

/*@
requires m >= 0;
requires n + (m - 1) <= INT_MAX;
requires n + (m - 1) >= INT_MIN;
assigns \nothing;
ensures \result == n * m;
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
