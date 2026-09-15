int mult(int n, int m);

/*@
requires n >= INT_MIN / (m == 0 ? 1 : m);
requires n >= 0;
requires n == 0 || m <= INT_MAX / (n > 0 ? n : -n);
requires n <= INT_MAX / (m == 0 ? 1 : m);
requires n <= INT_MAX && n >= INT_MIN;
requires m >= 0;
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
