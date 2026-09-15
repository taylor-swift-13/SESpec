int foo135(int x, int n);


/*@ logic integer ipow(integer b, integer e) =
      e <= 0 ? 1 : b * ipow(b, e - 1); */
/*@
  assigns \result \from x, n;
  ensures \result == (n <= 0 ? 1 : ipow(x, n));
*/
int foo135(int x, int n)
{
  if (n <= 0) {
    return 1;
  }

  int res = 1;

  /*@
    loop invariant 0 <= i <= n;
    loop invariant res == ipow(x, i);
    loop assigns i, res;
    loop variant n - i;
  */
  for (int i = 0; i < n; i++) {
    res = res * x;
  }

  return res;
}