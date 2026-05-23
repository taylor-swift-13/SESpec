
        /*@
  requires 0 <= leftElement <= rightElement < a_len;
  requires \valid_read(a + (0 .. a_len-1));
  assigns \nothing;
  ensures leftElement <= \result <= rightElement + 1;
  ensures \result <= a_len;
  ensures \result == leftElement || \result == rightElement + 1
       || (leftElement < \result && \result < rightElement + 1);
*/
int foo298(int *a, int a_len, int leftElement, int rightElement) {
  int i = leftElement;
  int j = rightElement;

  /*@
    loop invariant leftElement <= i <= j + 1;
    loop invariant leftElement <= i <= a_len;
    loop invariant -1 <= j < a_len;
    loop invariant j <= rightElement;
    loop assigns i, j;
    loop variant j - i + 1;
  */
  while (i <= j) {
    int mid = (i + j) / 2;
    if (a[mid] == mid) {
      i = mid + 1;
    } else {
      j = mid - 1;
    }
  }

  return i;
}
