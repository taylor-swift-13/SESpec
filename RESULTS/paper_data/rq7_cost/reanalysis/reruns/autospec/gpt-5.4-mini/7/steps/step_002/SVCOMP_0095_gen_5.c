int mult(int n, int m);

/*@
requires m >= 0;
requires n >= 0 || n <= 0;
requires m == 0 || m > 0;
assigns \nothing;
ensures m == 0 ==> \result == 0;
ensures m > 0 ==> \result == n * m;
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
