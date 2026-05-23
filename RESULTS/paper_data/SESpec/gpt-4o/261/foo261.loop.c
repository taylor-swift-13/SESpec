
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires a_len >= 0;
  requires \valid(a + (0 .. a_len - 1));
  requires \forall integer k; 0 <= k < a_len - 1 ==> a[k] <= a[k + 1];
  ensures \result >= 0 && \result <= a_len;
  ensures \result < a_len ==> a[\result] == x;
  ensures \result == a_len || a[\result] >= x;
*/
int foo261(int * a, int a_len, int x) {

    int i = 0;
    int j = a_len - 1;

    /*@
      loop invariant 0 <= i <= a_len;
      loop invariant -1 <= j < a_len;
      loop invariant i <= j + 1;
      loop invariant x == \at(x,Pre);
      loop invariant a_len == \at(a_len,Pre);
      loop invariant a == \at(a,Pre);
      loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k],Pre);
      loop assigns i, j;
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
