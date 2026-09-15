int mult(int n, int m);

/*@
requires n >= INT_MIN && n <= INT_MAX;
requires n >= 0 || n <= 0;
requires n >= 0 || m == 0;
requires n <= INT_MAX / (m == 0 ? 1 : m);
requires n * m <= INT_MAX;
requires m >= 0;
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
