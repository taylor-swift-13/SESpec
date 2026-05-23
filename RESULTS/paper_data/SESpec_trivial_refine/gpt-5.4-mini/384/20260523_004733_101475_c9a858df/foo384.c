
int comb_step(int n, int k)
{
  int c = 1;
  for (int i = 1; i <= k; i++) {
    c = c * (n - i + 1) / i;
  }
  return c;
}

/*@
  requires 0 <= k;
  assigns \nothing;
*/
int foo384(int n, int k) {

  if (k > n - k)
    k = n - k;

  int c = 1;

  /*@
    loop invariant 1 <= i;
    loop invariant k < 0 || i <= k + 1;
    loop assigns i, c;
    loop variant k - i + 1;
  */
  for (int i = 1; i <= k; i++) {
    c = c * (n - i + 1) / i;
  }

  return c;
}
