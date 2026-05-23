
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(array + (0..array_len-1));
  requires array_len > 0;
  requires count > 0;
  ensures \result >= 0 && \result < count;
*/
int foo179(int * array, int array_len, int count) {

    if (count == 0) {
        return 0;
    }
    int r = 0, top = count - 1;

    /*@
      loop invariant 0 <= r <= top && top < count;
      loop invariant count == \at(count,Pre);
      loop invariant array_len == \at(array_len,Pre);
      loop invariant array == \at(array,Pre);
      loop invariant \forall integer k; 0 <= k < array_len ==> array[k] == \at(array[k], Pre);
      loop assigns r, top;
    */
    while (r < top) {
        if (array[r] < array[top]) {
            return r + 1;
        }
        int end = (r + top) / 2;
        if (array[end] > array[r]) {
            r = end;
        } else {
            top = end;
        }
    }

    return r + 1;
}
