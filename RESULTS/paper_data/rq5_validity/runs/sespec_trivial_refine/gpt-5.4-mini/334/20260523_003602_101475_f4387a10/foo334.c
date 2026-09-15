
/*@
  requires 0 < n <= 1290;
  assigns \nothing;
*/
int foo334(int n) {
  int sum = 0;
  int sum1 = 0;

  /*@
    loop invariant 1 <= i <= n + 1;
    loop invariant 4 * sum == (i - 1) * (i - 1) * i * i;
    loop assigns i, sum;
    loop variant n - i + 1;
  */
  for (int i = 1; i <= n; i++) {
    sum += i * i * i;
  }

  /*@
    loop invariant 1 <= i <= n + 1;
    loop invariant sum1 == ((i - 1) * i) / 2;
    loop assigns i, sum1;
    loop variant n - i + 1;
  */
  for (int i = 1; i <= n; i++) {
    sum1 += i;
  }

  return sum - sum1;
}
