
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid_read(a + (0 .. a_len - 1));
  requires a_len >= 0;
  ensures \result == -1 || (0 <= \result < a_len && a[\result] == x && (\result == 0 || a[\result - 1] != x));
  ensures \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
  assigns \nothing;
*/
int foo185(int * a, int a_len, int x) {

    int low = 0, high = a_len - 1;

    /*@
      loop invariant 0 <= low <= a_len;
      loop invariant -1 <= high < a_len;
      loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
      loop invariant x == \at(x, Pre);
      loop invariant a_len == \at(a_len, Pre);
      loop invariant a == \at(a, Pre);
      loop assigns high, low;
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
