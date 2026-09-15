int mult(int n, int m);

/*@
requires m >= 0;
requires n + (m - 1) >= INT_MIN;
requires n + (m - 1) <= INT_MAX;
requires m >= 0 ==> n * m >= INT_MIN;
requires m >= 0 ==> n * m <= INT_MAX;
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
