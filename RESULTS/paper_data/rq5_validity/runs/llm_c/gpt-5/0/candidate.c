/*@ axiomatic Ack_axioms {
    logic integer Ack(integer m, integer n);

    axiom Ack_case0:
      \forall integer m, n; m == 0 ==> Ack(m, n) == n + 1;

    axiom Ack_case1:
      \forall integer m, n; m > 0 && n == 0 ==> Ack(m, n) == Ack(m - 1, 1);

    axiom Ack_case2:
      \forall integer m, n; m > 0 && n > 0 ==> Ack(m, n) == Ack(m - 1, Ack(m, n - 1));
  }
*/

int ack(int m, int n);

/*@ requires m >= 0 && n >= 0;
    assigns \nothing;
    ensures \result == Ack(m, n);
    ensures m == 0 ==> \result == n + 1;
    ensures m > 0 && n == 0 ==> \result == Ack(m - 1, 1);
    ensures m > 0 && n > 0 ==> \result == Ack(m - 1, Ack(m, n - 1));
    terminates \true;
    decreases m, n;
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
