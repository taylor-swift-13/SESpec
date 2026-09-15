
/*@
  logic integer max_index(int* array, integer lo, integer hi) =
    lo >= hi ? lo : (array[lo] >= array[max_index(array, lo + 1, hi)] ? lo : max_index(array, lo + 1, hi));
*/

/*@
  requires \valid(array + (0 .. array_len - 1));
  requires array_len > 0 && array_len < 100;
  ensures \result == max_index(array, 0, array_len);
  assigns \nothing;
*/
int foo202(int * array, int array_len, int Array) {

    int found = 0, top = Array - 1;

    /*@
      loop invariant Array == \at(Array, Pre);
      loop invariant array_len == \at(array_len, Pre);
      loop invariant array == \at(array, Pre);
      loop invariant 0 <= found <= top < array_len;
      loop invariant \forall integer k; found <= k <= top ==> array[k] <= array[found];
      loop assigns found, top;
      loop variant top - found;
    */
    while (found < top) {
        int i = found + (top - found) / 2;
        if (array[i] < array[i + 1]) {
            found = i + 1;
        } else {
            top = i;
        }
    }

    /*@
      ensures \result == found;
      ensures 0 <= \result < array_len;
      ensures \forall integer k; 0 <= k < array_len ==> array[k] <= array[\result];
    */
    return found;
}
