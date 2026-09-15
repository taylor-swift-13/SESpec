
        /*@
logic integer foo287_seq(integer n) =
  n <= 0 ? 0 :
  n == 1 ? 1 :
  foo287_seq(n - 1) + 2 * foo287_seq(n - 2);
*/
/*@
  requires c >= 1;
  assigns \nothing;
  ensures \result == foo287_seq(c);
*/
int foo287(int c) {
  int a = 0;
  int b = 1;

  /*@
    loop invariant 2 <= p <= c + 1;
    loop invariant a == foo287_seq(p - 2);
    loop invariant b == foo287_seq(p - 1);
    loop assigns p, a, b;
    loop variant c - p + 1;
  */
  for (int p = 2; p <= c; p++) {
    int t = b + 2 * a;
    a = b;
    b = t;
  }

  return b;
}
