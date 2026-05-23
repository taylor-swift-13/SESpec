
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(array + (0..array.length-1));
  requires array.length > 0;
  ensures \result == -1 || (0 <= \result < array.length && array[\result] == search);
  ensures \forall integer i; 0 <= i < array.length && array[i] == search ==> \result == i;
  assigns \nothing;
*/
int foo53(int search, int array[]) {
    int c;
    int location;

    /*@
      loop invariant 0 <= c <= array.length;
      loop invariant \forall integer i; 0 <= i < c ==> array[i] != search;
      loop invariant \exists integer loc; 0 <= loc < c ==> (array[loc] == search) ==> location == loc;
      loop assigns c, location;
    */
    for (c = 0; c < array.length; c++) {
        if (array[c] == search) {
            location = c;
            break;
        }
    }

    /*@
      ensures c == array.length ==> location == -1;
      ensures c < array.length ==> location == c && array[location] == search;
    */
    if (c == array.length) {
        location = -1;
    }
    return location;
}
