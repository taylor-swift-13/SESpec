int mult(int n, int m);

/*@
requires n >= 0;
requires n >= 0 || n <= 0;
requires n >= 0 || m == 0;
requires n == 0 || m >= 0;
requires n <= INT_MAX && n >= INT_MIN;
requires n * m <= INT_MAX && n * m >= INT_MIN;
requires m >= 0;
requires m == 0 || n == 0 || (m > 0 ==> n <= INT_MAX / m && n >= INT_MIN / m);
requires m == 0 || m > 0;
requires m == 0 || (n >= 0 ==> n <= INT_MAX / m) || (n < 0 ==> n >= INT_MIN / m);
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
