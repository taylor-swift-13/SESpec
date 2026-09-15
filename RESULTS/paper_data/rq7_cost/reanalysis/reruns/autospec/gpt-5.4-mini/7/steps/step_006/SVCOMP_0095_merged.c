int mult(int n, int m);

/*@
requires n == 0 || m >= 0;
ensures m == 0 ==> \result == 0;
ensures m > 0 ==> \result == n * m;
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
