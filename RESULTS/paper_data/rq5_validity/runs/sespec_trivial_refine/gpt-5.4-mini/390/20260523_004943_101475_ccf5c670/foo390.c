
/*@ logic integer fallfact(integer n, integer k) =
      (k < 1) ? 1 : fallfact(n, k - 1) * (n - k + 1);
*/
/*@
  assigns \nothing;
*/
int foo390(int n, int k) {

  int res = 1;
  int i = 1;

  /*@
    loop invariant 1 <= i;
    loop invariant k >= 1 ==> i <= k + 1;
    loop invariant res == fallfact(n, i - 1);
    loop assigns res, i;
    loop variant k - i + 1;
  */
  while (i <= k) {
    res *= (n - i + 1);
    i++;
  }

  return res;
}
