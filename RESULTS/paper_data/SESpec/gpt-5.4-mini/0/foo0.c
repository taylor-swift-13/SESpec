
/*@
  logic integer ack(integer m, integer n) =
    m == 0 ? n + 1 :
    n == 0 ? ack(m - 1, 1) :
             ack(m - 1, ack(m, n - 1));
*/

/*@
  requires m >= 0;
  requires n >= 0;
  decreases m + n;
  assigns \nothing;
  ensures \result == ack(m, n);
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
