int addition(int m, int n);

/*@ 
  assigns \nothing;
  ensures \result == m + n;
  behavior zero:
    assumes n == 0;
    ensures \result == m;
  behavior pos:
    assumes n > 0;
    ensures \result == m + n;
  behavior neg:
    assumes n < 0;
    ensures \result == m + n;
  complete behaviors zero, pos, neg;
  disjoint behaviors zero, pos, neg;
  decreases \abs(n);
*/
int addition(int m, int n) {

        if (n == 0) {
            return m;
        }
        if (n > 0) {
            return addition(m + 1, n - 1);
        } else {
            return addition(m - 1, n + 1);
        }
}
