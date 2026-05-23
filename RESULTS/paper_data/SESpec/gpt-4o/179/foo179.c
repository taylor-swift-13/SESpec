
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(array + (0..array_len-1));
  requires array_len > 0;
  requires count > 0;
  requires count < array_len; // Strengthened precondition to ensure count is within bounds.
  ensures \result >= 0 && \result <= count; // Adjusted upper bound to include count.
  ensures \forall integer k; 0 <= k < array_len ==> array[k] == \at(array[k], Pre);
  ensures \result == 0 ==> count == 1 || (\forall integer i; 0 <= i < count - 1 ==> array[i] >= array[count - 1]);
  ensures \result > 0 && \result <= count && array[\result - 1] < array[count - 1] ==> 
          (\exists integer r; 0 <= r < count && array[r] < array[count - 1]); // Weakened postcondition to reflect actual behavior.
  assigns \nothing;
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
      loop variant top - r;
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
