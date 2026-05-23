
/*@
predicate arrays_equal{L}(int *a, int *b, integer n) =
  \forall integer k; 0 <= k < n ==> a[k] == b[k];
*/

/*@
  requires a_len >= 0 && b_len >= 0;
  requires a_len == 0 || \valid_read(a + (0 .. a_len - 1));
  requires b_len == 0 || \valid_read(b + (0 .. b_len - 1));
  assigns \nothing;

  behavior equal:
    assumes a_len == b_len && arrays_equal(a, b, a_len);
    ensures \result == 1;

  behavior notequal_len:
    assumes a_len != b_len;

  behavior notequal_content:
    assumes a_len == b_len && !arrays_equal(a, b, a_len);

  ensures 0 <= \result <= 1;

  complete behaviors;
  disjoint behaviors;
*/
int foo95(int *a, int a_len, int *b, int b_len)
{
  if (a_len != b_len) {
    return 0;
  }

  /*@
    loop invariant 0 <= i <= a_len;
    loop invariant \forall integer k; 0 <= k < i ==> a[k] == b[k];
    loop assigns i;
    loop variant a_len - i;
  */
  for (int i = 0; i < a_len; i++) {
    if (a[i] != b[i]) {
      return 0;
    }
  }

  return 1;
}
