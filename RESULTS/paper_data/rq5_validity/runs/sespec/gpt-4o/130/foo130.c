
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(array + (0..array_len-1));
  requires array_len >= 0;
  ensures \result == -1 || (0 <= \result < array_len && array[\result] == search);
  ensures \forall integer i; 0 <= i < array_len ==> array[i] == \at(array[i], Pre);
  assigns \nothing;
*/
int foo130(int search, int array[], int array_len) {

    int location = -1;
    int c;

    /*@
      loop invariant 0 <= c <= array_len;
      loop invariant location == -1 || (0 <= location < c && array[location] == search);
      loop invariant \forall integer i; 0 <= i < c ==> array[i] == \at(array[i], Pre);
      loop assigns c, location;
      loop variant array_len - c;
    */
    for (c = 0; c < array_len; c++) {
        if (array[c] == search) {
            location = c;
            break;
        }
    }

    /*@
      ensures location == -1 || (0 <= location < array_len && array[location] == search);
      ensures \forall integer i; 0 <= i < array_len ==> array[i] == \at(array[i], Pre);
    */
    if (c == array_len) {
        location = -1;
    }
    return location;
}
