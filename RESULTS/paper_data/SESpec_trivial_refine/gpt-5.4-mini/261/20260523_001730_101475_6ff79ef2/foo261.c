
        /*@
  requires a_len >= 0;
  requires a_len == 0 || \valid_read(a + (0 .. a_len - 1));
  assigns \nothing;
  ensures 0 <= \result <= a_len;
*/
int foo261(int *a, int a_len, int x) {
  int i = 0;
  int j = a_len - 1;

  /*@
    loop invariant 0 <= i <= a_len;
    loop invariant -1 <= j < a_len;
    loop invariant i <= j + 1;
    loop assigns i, j;
    loop variant j - i + 1;
  */
  while (i <= j) {
    int mid = (i + j) / 2;
    if (a[mid] == x) {
      return mid;
    } else if (a[mid] < x) {
      i = mid + 1;
    } else {
      j = mid - 1;
    }
  }

  return i;
}
