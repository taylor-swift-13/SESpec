
/*@
predicate sorted{L}(int *a, integer n) =
  \forall integer i, j; 0 <= i <= j < n ==> a[i] <= a[j];
*/

/*@
  requires 0 <= a_len;
  requires \valid_read(a + (0 .. a_len - 1));
  requires sorted(a, a_len);
  assigns \nothing;
  ensures \result == -1 || (0 <= \result < a_len);
  ensures \result != -1 ==> a[\result] == x;
  ensures \result != -1 ==> (\result == 0 || a[\result - 1] != x);
*/
int foo185(int * a, int a_len, int x) {

  int low = 0, high = a_len - 1;

  /*@
    loop invariant 0 <= low <= a_len;
    loop invariant -1 <= high < a_len;
    loop invariant low <= high + 1;
    loop invariant sorted(a, a_len);
    loop assigns low, high;
  */
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (a[mid] == x) {
      if (mid == 0 || a[mid - 1] != x) {
        return mid;
      } else {
        high = mid - 1;
      }
    } else if (a[mid] < x) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return -1;
}
