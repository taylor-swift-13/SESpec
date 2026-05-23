
/*@
logic integer sum_odd_range(integer l, integer r) =
  l > r ? 0 : ((l % 2 != 0 ? l : 0) + sum_odd_range(l + 1, r));
*/
/*@
  assigns \nothing;
  ensures l > r ==> \result == 0;
*/
int foo378(int l, int r) {
  if (l > r) {
    return 0;
  }

  int sum = 0;

  /*@
    loop invariant l <= i <= r + 1;
    loop assigns i, sum;
    loop variant r - i + 1;
  */
  for (int i = l; i <= r; i++) {
    if (i % 2 != 0) {
      sum += i;
    }
  }

  return sum;
}
