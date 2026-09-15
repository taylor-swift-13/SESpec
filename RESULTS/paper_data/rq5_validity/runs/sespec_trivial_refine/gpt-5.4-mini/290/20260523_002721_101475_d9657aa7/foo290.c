
/*@ logic integer foo290_val(integer n) =
      n == 0 ? 2 :
      n == 1 ? 1 :
      foo290_val(n - 1) + 2 * foo290_val(n - 2); */

/*@
  requires 1 <= c;
  assigns \nothing;
  ensures \result == foo290_val(c);
*/
int foo290(int c) {
  int a = 2;
  int b = 1;

  if (c == 1) return 1;

  /*@
    loop invariant 2 <= p <= c + 1;
    loop invariant a == foo290_val(p - 2);
    loop invariant b == foo290_val(p - 1);
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
