
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(array + (0..array_len-1));
  requires array_len >= 0;
  requires Array > 0;
  ensures \result >= 0;
  ensures \result <= Array;
  ensures \forall integer v; 0 <= v < Array ==>
            count_eq(array, 0, array_len, v) == \at(count_eq(array, 0, array_len, v), Pre);
*/
int foo203(int * array, int array_len, int Array) {

    int find = 0;
    int offset = 0;
    int max = 1;

    /*@
      loop invariant 0 <= offset <= Array;
      loop invariant 1 <= max <= Array;
      loop invariant 0 <= find <= offset;
      loop invariant \forall integer k; 0 <= k < offset ==> array[k] == \at(array[k], Pre);
      loop invariant \forall integer k; 0 <= k < max ==> array[k] == \at(array[k], Pre);
      loop invariant \forall integer v; 0 <= v < Array ==>
                       count_eq(array, 0, array_len, v) == \at(count_eq(array, 0, array_len, v), Pre);
      loop invariant (!(0 < \at(Array,Pre) && 1 < \at(Array,Pre))) ==> ((max == 1)&&(offset == 0)&&(find == 0)&&(Array == \at(Array,Pre))&&(array_len == \at(array_len,Pre))&&(array == \at(array,Pre)));
      loop invariant Array == \at(Array,Pre);
      loop invariant array_len == \at(array_len,Pre);
      loop invariant array == \at(array,Pre);
      loop assigns offset, max, find;
    */
    while (offset < Array && max < Array) {
        if (array[offset] == array[max]) {
            offset++;
            max++;
            find++;
        } else if (array[offset] > array[max]) {
            offset++;
        } else {
            max++;
        }
    }

    return find;
}
