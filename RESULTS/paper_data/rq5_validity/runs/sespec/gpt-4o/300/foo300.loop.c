
/*@
  logic integer max_index(int* array, integer lo, integer hi) =
    lo >= hi - 1 ? lo : (array[lo] < array[hi - 1] ? max_index(array, lo + 1, hi) : lo);
*/

/*@
  requires \valid(array + (0..array_len-1));
  requires array_len > 0;
  ensures 0 <= \result < array_len;
  ensures \forall integer k; 0 <= k < array_len ==> array[\result] >= array[k];
  ensures \result == max_index(array, 0, array_len);
*/
int foo300(int * array, int array_len, int Array) {

    int found = 0, top = Array - 1;

    /*@
      loop invariant Array == \at(Array, Pre);
      loop invariant array_len == \at(array_len, Pre);
      loop invariant array == \at(array, Pre);
      loop invariant \forall integer k; 0 <= k < array_len ==> array[k] == \at(array[k], Pre);
      loop assigns found, top;
    */
    while (found < top) {
        int i = found + (top - found) / 2;
        if (array[i] < array[i + 1]) {
            found = i + 1;
        } else {
            top = i;
        }
    }

    return found;
}
