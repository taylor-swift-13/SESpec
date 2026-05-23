
/*@
  logic integer max_index(int* data, integer lo, integer hi) =
    lo >= hi ? lo : (data[lo] >= data[max_index(data, lo + 1, hi)] ? lo : max_index(data, lo + 1, hi));
*/

/*@
  requires \valid(data + (0..data_len-1));
  requires data_len > 0;
  ensures 0 <= \result < data_len;
  ensures \forall integer k; 0 <= k < data_len ==> data[k] <= data[\result];
*/
int foo301(int * data, int data_len, int array) {

    int found = 0, top = array - 1;

    /*@
      loop invariant array == \at(array, Pre);
      loop invariant data_len == \at(data_len, Pre);
      loop invariant data == \at(data, Pre);
      loop assigns found, top;
    */
    while (found < top) {
        int i = found + (top - found) / 2;
        if (data[i] < data[i + 1]) {
            found = i + 1;
        } else {
            top = i;
        }
    }

    return found;
}
