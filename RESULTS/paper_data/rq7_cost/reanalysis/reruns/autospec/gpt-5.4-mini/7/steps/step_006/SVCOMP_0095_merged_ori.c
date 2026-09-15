int mult(int n, int m);

/*@
requires n >= 0;
requires n >= 0 || n <= 0;
requires n >= 0 || m == 0;
requires n == 0 || m >= 0;
requires n <= INT_MAX;
requires n <= INT_MAX && n >= INT_MIN;
requires n + (m - 1) * n >= INT_MIN;
requires n + (m - 1) * n <= INT_MAX;
requires m >= 0;
requires m <= INT_MAX;
ensures m > 0 ==> \result == n * m;
ensures m == 0 ==> \result == 0;
ensures \result == n * m;
ensures \result == 0;
behavior zero:;
behavior positive:;
assumes m > 0;
assumes m == 0;
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
