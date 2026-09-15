int mult(int n, int m);

/*@ 
  requires \forall integer k; 0 <= k <= \abs(m) ==> INT_MIN <= k * n <= INT_MAX;
  assigns \nothing;
  ensures \result == n * \abs(m);

  behavior zero:
    assumes m == 0;
    ensures \result == 0;

  behavior pos:
    assumes m > 0;
    ensures \result == n * m;

  behavior neg:
    assumes m < 0;
    ensures \result == n * (-m);

  complete behaviors zero, pos, neg;
  disjoint behaviors zero, pos, neg;
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
