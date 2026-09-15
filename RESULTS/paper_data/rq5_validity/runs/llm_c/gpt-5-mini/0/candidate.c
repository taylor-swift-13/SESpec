int ack(int m, int n);

/*@
    requires m >= 0 && n >= 0;
    assigns \nothing;
    decreases m, n;
    ensures \result >= 0;
*/
int ack(int m, int n) {

    if (m == 0) {
      return n + 1;
    }
    if (n == 0) {
      return ack(m - 1, 1);
    }
    return ack(m - 1, ack(m, n - 1));
}
