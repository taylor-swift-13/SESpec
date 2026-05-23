
/*@
  logic integer sorted_prefix(int* a, integer lo, integer hi) =
    (lo >= hi - 1) ? 1 : (a[lo] <= a[lo + 1] ? sorted_prefix(a, lo + 1, hi) : 0);
*/

/*@
  requires \valid(a + (0 .. a_len - 1));
  requires a_len > 0;
  requires sorted_prefix(a, 0, a_len) == 1;
  assigns \nothing;
  ensures \result == -1 || (0 <= \result < a_len && a[\result] == x && (\result == a_len - 1 || a[\result + 1] != x));
*/
int foo182(int * a, int a_len, int x) {

    int low = 0;
    int high = a_len - 1;
    int mid = 0;

    /*@
      loop invariant 0 <= low <= a_len;
      loop invariant -1 <= high < a_len;
      loop invariant low <= high + 1;
      loop invariant sorted_prefix(a, 0, a_len) == 1;
      loop invariant x == \at(x, Pre);
      loop invariant a_len == \at(a_len, Pre);
      loop invariant \valid(a + (0 .. a_len - 1));
      loop assigns mid, low, high;
      loop variant high - low + 1;
    */
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == x) {
            if (mid == a_len - 1 || a[mid + 1] != x) {
                return mid;
            } else {
                low = mid + 1;
            }
        } else if (a[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}
