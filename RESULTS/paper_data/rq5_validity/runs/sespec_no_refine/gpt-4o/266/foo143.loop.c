
/*@
  logic integer count_odd(int* array, integer lo, integer hi) =
    lo >= hi ? 0
             : count_odd(array, lo, hi - 1) + (array[hi - 1] % 2 != 0 ? 1 : 0);
*/

/*@
  logic integer last_odd(int* array, integer lo, integer hi) =
    lo >= hi ? 0
             : (array[hi - 1] % 2 != 0 ? array[hi - 1] : last_odd(array, lo, hi - 1));
*/

/*@
  requires \at(array_len, Pre) > 0 && \at(array_len, Pre) < 100;
  requires \valid(array + (0 .. array_len - 1));
  ensures \result == 0 || (\exists integer i; 0 <= i < array_len && array[i] == \result && array[i] % 2 != 0);
  ensures \forall integer i; 0 <= i < array_len ==> array[i] == \at(array[i], Pre);
*/
int foo143(int * array, int array_len, int Array) {

    int ret = 0;
    int start = 0;

    /*@
      loop invariant \forall integer i; 0 <= i < array_len ==> array[i] == \at(array[i], Pre);
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
