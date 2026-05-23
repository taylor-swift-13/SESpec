
/*@
  logic integer max_index(int* data, integer lo, integer hi) =
    lo >= hi ? lo : (data[lo] >= data[max_index(data, lo + 1, hi)] ? lo : max_index(data, lo + 1, hi));
*/

/*@
  requires \valid(data + (0..data_len-1));
  requires data_len > 0;
  requires 0 < array <= data_len;
  requires \forall integer i, j; 0 <= i < j < array ==> data[i] <= data[j]; // Array must be sorted
  ensures 0 <= \result < array;
  assigns \nothing;
*/
int foo301(int * data, int data_len, int array) {

    int found = 0, top = array - 1;

    /*@
      loop invariant 0 <= found <= top < array;
      loop invariant \forall integer k; 0 <= k < found ==> data[k] <= data[found];
      loop invariant \forall integer i, j; 0 <= i < j < array ==> data[i] <= data[j]; // Array remains sorted
      loop invariant array == \at(array, Pre);
      loop invariant data_len == \at(data_len, Pre);
      loop invariant data == \at(data, Pre);
      loop assigns found, top;
      loop variant top - found;
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
