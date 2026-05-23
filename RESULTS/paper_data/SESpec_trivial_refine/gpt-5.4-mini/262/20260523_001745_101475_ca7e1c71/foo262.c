
/*@
predicate sorted{L}(int *a, integer n) =
  \forall integer i, j; 0 <= i <= j < n ==> a[i] <= a[j];
*/

/*@
  requires a_len >= 0;
  requires a_len == 0 || \valid_read(a + (0 .. a_len - 1));
  requires sorted(a, a_len);
  assigns \nothing;
  ensures 0 <= \result <= a_len;
  ensures (\exists integer i; 0 <= i < a_len && a[i] == x) ==> 0 <= \result < a_len && a[\result] == x;
  ensures (\forall integer i; 0 <= i < a_len && a[i] != x) ==>
            (\forall integer i; 0 <= i < \result ==> a[i] < x) &&
            (\forall integer i; \result <= i < a_len ==> a[i] > x);
*/
int foo262(int *a, int a_len, int x)
{
  int i = 0;

  /*@
    loop invariant 0 <= i <= a_len;
    loop invariant \forall integer k; 0 <= k < i ==> a[k] < x;
    loop assigns i;
    loop variant a_len - i;
  */
  while (i < a_len && a[i] < x) {
    i++;
  }

  if (i < a_len && a[i] == x) {
    return i;
  }

  return i;
}
