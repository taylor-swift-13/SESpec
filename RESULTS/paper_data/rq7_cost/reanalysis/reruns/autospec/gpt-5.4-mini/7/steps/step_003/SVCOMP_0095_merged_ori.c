int mult(int n, int m);

/*@
requires n >= INT_MIN && n <= INT_MAX;
requires n >= 0 || m == 0;
requires n == 0 || m <= INT_MAX / n;
requires n == 0 || m <= INT_MAX / (n > 0 ? n : -n);
requires n <= INT_MAX && n >= INT_MIN;
requires n + (m - 1) >= INT_MIN;
requires n + (m - 1) <= INT_MAX;
requires m >= 0;
requires m >= 0 ==> n * m >= INT_MIN;
requires m >= 0 ==> n * m <= INT_MAX;
requires m == 0 || n >= INT_MIN / (m == 1 ? 1 : m);
requires m == 0 || (n >= INT_MIN - n && n <= INT_MAX - n);
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
