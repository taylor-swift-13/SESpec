
/*@
  logic integer max_index(int* array, integer lo, integer hi) =
    lo >= hi - 1 ? lo : (array[lo] < array[hi - 1] ? max_index(array, lo + 1, hi) : lo);
*/

/*@
  requires \valid(array + (0..array_len-1));
  requires array_len > 0;
  requires Array > 0 && Array <= array_len;
  ensures 0 <= \result < Array;
  
*/
int foo300(int * array, int array_len, int Array) {

    int found = 0, top = Array - 1;

    /*@
      loop invariant Array == \at(Array, Pre);
      loop invariant array_len == \at(array_len, Pre);
      loop invariant array == \at(array, Pre);
      loop invariant \forall integer k; 0 <= k < array_len ==> array[k] == \at(array[k], Pre);
      loop invariant 0 <= found <= top < Array;
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
      ensures found == top;
      ensures \forall integer k; 0 <= k < Array ==> array[found] >= array[k];
    */
    return found;
}
