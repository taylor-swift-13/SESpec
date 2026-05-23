
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires array >= 0;
  requires ints_len >= array;
  requires \valid(ints + (0 .. ints_len - 1));
  
  ensures \result >= 0;
  ensures \result <= array;
*/
int foo204(int * ints, int ints_len, int array) {

    int find = 0;
    int offset = 0;
    int max = 1;

    /*@
      loop invariant 0 <= offset <= array;
      loop invariant 1 <= max <= array + 1;
      loop invariant 0 <= find <= offset;
      loop invariant (0 < array && 1 < array) ==> (offset <= max);
      loop invariant (0 < array && 1 < array) ==> (max <= array + 1);
      loop invariant (!(0 < array && 1 < array)) ==> ((max == 1)&&(offset == 0)&&(find == 0)&&(array == \at(array,Pre))&&(ints_len == \at(ints_len,Pre))&&(ints == \at(ints,Pre)));
      loop invariant array == \at(array,Pre);
      loop invariant ints_len == \at(ints_len,Pre);
      loop invariant ints == \at(ints,Pre);
      loop assigns offset, max, find;
      loop variant array - offset;
    */
    while (offset < array && max < array) {
        if (ints[offset] == ints[max]) {
            offset++;
            max++;
            find++;
        } else if (ints[offset] > ints[max]) {
            offset++;
        } else {
            max++;
        }
    }

    return find;
}
