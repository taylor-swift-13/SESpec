int mult(int n, int m);

/*@
requires m >= 0;
requires n <= INT_MAX && n >= INT_MIN;
requires m == 0 || n == 0 || (m > 0 ==> n <= INT_MAX / m && n >= INT_MIN / m);
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
