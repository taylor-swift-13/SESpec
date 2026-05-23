
/*@
  logic integer count_odd(int* array, integer lo, integer hi) =
    lo >= hi ? 0
             : count_odd(array, lo, hi - 1) + (array[hi - 1] % 2 != 0 ? 1 : 0);
*/

/*@
  requires \valid(array + (0..array_len-1));
  requires array_len >= 0;
  requires Array >= 0; // Strengthened precondition to ensure Array is non-negative
  ensures \result == 0 || (\exists integer k; 0 <= k < Array && array[k] % 2 != 0 && \result == array[k]);
  ensures \forall integer k; 0 <= k < Array ==> array[k] == \at(array[k], Pre);
  ensures Array == \at(Array, Pre);
  ensures array_len == \at(array_len, Pre);
  ensures array == \at(array, Pre);
*/
int foo266(int * array, int array_len, int Array) {

    int ret = 0;
    int start = 0;

    /*@
      loop invariant 0 <= index <= Array;
      loop invariant 0 <= start <= count_odd(array, 0, index);
      loop invariant \forall integer k; 0 <= k < index ==> array[k] == \at(array[k], Pre);
      loop invariant Array == \at(Array, Pre);
      loop invariant array_len == \at(array_len, Pre);
      loop invariant array == \at(array, Pre);
      loop assigns index, ret, start;
    */
    for (int index = 0; index < Array; index++) {
        if (array[index] % 2 != 0) {
            start++;
            if (start % 2 != 0) {
                ret = array[index];
            }
        }
    }

    return ret;
}
