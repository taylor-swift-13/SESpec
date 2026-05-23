
/*@
logic integer sum_prefix(int *a, integer n) = 
  (n <= 0) ? 0 : sum_prefix(a, n - 1) + a[n - 1];
*/

/*@ logic integer pow2(integer n) = n <= 0 ? 1 : 2 * pow2(n - 1); */
/*@
  requires 0 <= b;
  assigns \nothing;
  ensures \result == pow2(b);
  ensures \result >= 1;
  ensures \result == 1 <==> b == 0;
*/
int foo227(int b)
{
  int r = 1;

  /*@
    loop invariant 1 <= i <= b + 1;
    loop invariant r == pow2(i - 1);
    loop invariant r >= 1;
    loop assigns i, r;
    loop variant b + 1 - i;
  */
  for (int i = 1; i < b + 1; i++) {
    r = 2 * r;
  }

  return r;
}
