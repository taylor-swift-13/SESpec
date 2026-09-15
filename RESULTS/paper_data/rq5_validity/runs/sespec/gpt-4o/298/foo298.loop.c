
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

int foo298(int * a, int a_len, int leftElement, int rightElement) {

    int i = leftElement;
    int j = rightElement;

    /*@
      loop invariant rightElement == \at(rightElement,Pre);
      loop invariant leftElement == \at(leftElement,Pre);
      loop invariant a_len == \at(a_len,Pre);
      loop invariant a == \at(a,Pre);
      loop assigns i, j;
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
