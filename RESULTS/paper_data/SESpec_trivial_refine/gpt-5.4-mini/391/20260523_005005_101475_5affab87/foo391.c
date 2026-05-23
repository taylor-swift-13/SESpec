
        /*@
  assigns \nothing;
  ensures n < 1 ==> \result == 1;
  ensures \result > n;
  ensures \result == 1 <==> n < 1;
*/
int foo391(int n) {
  int i = 1;
  int square = 1;

  if (n < 1) {
    return 1;
  }

  /*@
    loop invariant i >= 1;
    loop invariant i <= n + 1;
    loop invariant square == i * i;
    loop assigns i, square;
    loop variant n - i + 1;
  */
  while (square <= n) {
    i++;
    square = i * i;
  }

  return square;
}
