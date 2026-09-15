
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
  logic integer is_in_range{L}(int* a, integer lo, integer hi, integer x) =
    lo >= hi ? 0
             : (a[lo] == x ? 1 : is_in_range(a, lo + 1, hi, x));
*/

int foo127(int * a, int a_len, int x) {

    int i = 0;
    int j = a_len - 1;

    /*@
      loop invariant x == \at(x,Pre);
      loop invariant a_len == \at(a_len,Pre);
      loop invariant a == \at(a,Pre);
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
