
/*@ logic integer foo294_seq(integer n) =
      n == 0 ? 0 :
      n == 1 ? 1 :
      (2 * foo294_seq(n - 1) + foo294_seq(n - 2)) % 1000000000; */
/*@ 
  requires p >= 1;
  assigns \nothing;
  ensures \result == foo294_seq(p);
  ensures \result >= 0;
*/
int foo294(int p) {
  int a = 0;
  int b = 1;
  int count = 2;
  int c;

  /*@
    loop invariant 2 <= count <= p + 1;
    loop invariant a == foo294_seq(count - 2);
    loop invariant b == foo294_seq(count - 1);
    loop invariant a >= 0 && b >= 0;
    loop assigns count, a, b, c;
    loop variant p - count + 1;
  */
  for (; count <= p; count++) {
    c = (2 * b + a) % 1000000000;
    a = b;
    b = c;
  }

  return b;
}
