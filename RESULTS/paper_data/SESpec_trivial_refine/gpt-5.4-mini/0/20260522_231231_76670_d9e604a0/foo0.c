
/*@
  requires 0 <= m;
  requires 0 <= n;
  assigns \nothing;
  ensures \result >= 1;
*/
int foo0(int m, int n);


int foo0(int m, int n) {

    if (m == 0) {
      return n + 1;
    }
    if (n == 0) {
      return foo0(m - 1, 1);
    }
    return foo0(m - 1, foo0(m, n - 1));
}
