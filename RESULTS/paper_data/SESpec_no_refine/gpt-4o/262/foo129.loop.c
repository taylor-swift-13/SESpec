
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  logic integer sorted{L}(int* a, integer lo, integer hi) =
    lo >= hi - 1 ? 1
                 : (a[lo] <= a[lo + 1] ? sorted(a, lo + 1, hi) : 0);
*/

/*@
  requires \valid(a + (0..\at(a_len,Pre) - 1));
  requires \at(a_len,Pre) > 0 && \at(a_len,Pre) < 100;
  requires sorted(a, 0, \at(a_len,Pre));
  ensures \result >= 0 && \result <= \at(a_len,Pre);
  ensures \forall integer k; 0 <= k < \at(a_len,Pre) ==> a[k] == \at(a[k],Pre);
*/
int foo129(int * a, int a_len, int x) {

    int left = 0;
    int right = a_len - 1;

    /*@
      loop invariant 0 <= left <= right + 1 <= \at(a_len,Pre);
      loop invariant \forall integer k; 0 <= k < \at(a_len,Pre) ==> a[k] == \at(a[k],Pre);
      loop invariant sorted(a, 0, \at(a_len,Pre));
      loop assigns left, right;
    */
    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == x) {
            return mid;
        } else if (a[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left;
}
