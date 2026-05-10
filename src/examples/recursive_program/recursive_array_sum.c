/*@
  logic integer arrsum(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : a[lo] + arrsum(a, lo + 1, hi);
*/

/*@
  requires \valid_read(a + (lo..hi-1));
  requires lo <= hi;
  decreases hi - lo;
  ensures \result == arrsum(a, lo, hi);
*/
int recursive_sum(int* a, int lo, int hi) {
    if (lo >= hi) {
        return 0;
    }
    return a[lo] + recursive_sum(a, lo + 1, hi);
}
