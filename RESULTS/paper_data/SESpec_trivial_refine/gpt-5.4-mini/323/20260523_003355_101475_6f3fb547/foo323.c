
/*@ logic integer foo323_count(integer n, integer i) =
      i > n / i ? 0 : ((n % i == 0 ? 1 : 0) + (i == n / i ? 0 : foo323_count(n, i + 1))); */
/*@
  requires n >= 0;
  assigns \nothing;
  ensures n == 1 ==> \result == 1;
  ensures n != 1 ==> \result >= 0;
*/
int foo323(int n) {
  int count = 0;

  if (n == 1) return 1;

  /*@
    loop invariant i >= 2;
    loop invariant count >= 0;
    loop invariant count <= i - 2;
    loop assigns count, i;
    loop variant n - i;
  */
  for (int i = 2; i <= n / i; i++) {
    if (n % i == 0) {
      count++;
      if (n / i == i) {
        break;
      }
    }
  }

  return count;
}
