int mult(int n, int m);

/*@
requires n >= INT_MIN;
requires n >= 0 || n <= 0;
requires n >= 0 || m == 0;
requires n <= INT_MAX;
requires n <= INT_MAX / (m > 0 ? m : 1);
requires n <= INT_MAX && n >= INT_MIN;
requires n * m >= INT_MIN;
requires n * m <= INT_MAX;
requires n * m <= INT_MAX && n * m >= INT_MIN;
requires m >= 0;
requires m == 0 || mult(n, m - 1) >= INT_MIN - n;
requires m == 0 || mult(n, m - 1) <= INT_MAX - n;
requires m <= INT_MAX;
ensures m > 0 ==> \result == n * m;
ensures m == 0 ==> \result == 0;
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
