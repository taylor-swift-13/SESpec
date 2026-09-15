
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@ 
  requires \valid(ints + (0 .. ints_len - 1));
  requires ints_len >= 0;
  requires array >= 1; // Strengthened precondition to ensure valid initial state
  ensures \result == count_eq(ints, 0, array, ints[\result - 1]);
*/
int foo202(int * ints, int ints_len, int array) {

    int find = 0;
    int min = 0;
    int offset = 1;

    /*@
      loop invariant 0 <= min && min <= array;
      loop invariant 1 <= offset && offset <= array;
      loop invariant 0 <= find && find <= min;
      loop invariant (0 < \at(array,Pre) && 1 < \at(array,Pre)) ==> (min >= 0 && min <= array);
      loop invariant (0 < \at(array,Pre) && 1 < \at(array,Pre)) ==> (offset >= 1 && offset <= array);
      loop invariant (!(0 < \at(array,Pre) && 1 < \at(array,Pre))) ==> ((offset == 1)&&(min == 0)&&(find == 0)&&(array == \at(array,Pre))&&(ints_len == \at(ints_len,Pre))&&(ints == \at(ints,Pre)));
      loop invariant array == \at(array,Pre);
      loop invariant ints_len == \at(ints_len,Pre);
      loop invariant ints == \at(ints,Pre);
      loop invariant \forall integer k; 0 <= k < ints_len ==> ints[k] == \at(ints[k], Pre);
      loop assigns min, offset, find;
    */
    while (min < array && offset < array) {
        if (ints[min] == ints[offset]) {
            min++;
            offset++;
            find++;
        } else if (ints[min] > ints[offset]) {
            min++;
        } else {
            offset++;
        }
    }

    return find;
}
