
        /*@
  assigns \nothing;
  ensures \result >= 0;
*/
int foo349(int n) {

  int sum = 0;

  /*@
    loop invariant 1 <= i;
    loop invariant n < 1 || i <= n + 1;
    loop invariant sum >= 0;
    loop assigns i, sum;
    loop variant n - i + 1;
  */
  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      if (i % 2 != 0) {
        sum += i;
      }
    }
  }

  return sum;
}
