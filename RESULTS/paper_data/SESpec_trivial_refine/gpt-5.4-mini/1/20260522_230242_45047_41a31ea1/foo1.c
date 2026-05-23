
/*@
  requires \true;
  decreases n >= 0 ? n : -n;
  assigns \nothing;
  ensures \result == m + n;
  ensures n == 0 ==> \result == m;
  ensures n > 0 ==> \result >= m;
  ensures n < 0 ==> \result <= m;
*/
int foo1(int m, int n) {
  if (n == 0) {
    return m;
  }
  if (n > 0) {
    return foo1(m + 1, n - 1);
  } else {
    return foo1(m - 1, n + 1);
  }
}
