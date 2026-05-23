
/*@
  predicate unchanged_array{L1, L2}(int* a, integer lo, integer hi) =
    \forall integer k; lo <= k <= hi ==> \at(a[k], L1) == \at(a[k], L2);
*/

/*@
  requires \valid(a + (0..a_len-1));
  requires a_len > 0 && a_len < 100;
  ensures \result >= 0 && \result < a_len || \result == 0;
*/
int foo174(int * a, int a_len) {

    int start = 0;
    int end = a_len - 1;

    /*@
      loop invariant 0 <= start <= a_len;
      loop invariant -1 <= end < a_len;
      loop invariant start <= end + 1;
      loop invariant unchanged_array{Pre, Here}(a, 0, a_len - 1);
      loop invariant a_len == \at(a_len, Pre);
      loop invariant a == \at(a, Pre);
      loop assigns start, end;
    */
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (mid < end && a[mid] > a[mid + 1]) {
            return mid + 1;
        } else if (mid > start && a[mid] < a[mid - 1]) {
            return mid;
        }
        if (a[mid] >= a[start]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return 0;
}
