
/*@
  logic integer count_pairs(int* array, integer lo, integer hi, integer p) =
    lo >= hi ? 0
             : count_pairs(array, lo, hi - 1, p) +
               (array[hi - 1] + array[lo] == p ? 1 : 0);
*/

/*@
  requires \valid(array + (0 .. array_len - 1));
  requires array_len >= 0;
  requires num >= 0 && num <= array_len;
  requires p >= 0;
  ensures \result >= 0; // Guaranteed because ret is initialized to 0 and only incremented.
  assigns \nothing;
*/
int foo103(int * array, int array_len, int num, int p) {

    int ret = 0;

    /*@
      loop invariant 0 <= index <= num;
      loop invariant ret >= 0; // Companion invariant to ensure non-negativity.
      loop assigns index, ret;
      loop variant num - index;
    */
    for (int index = 0; index < num; index++) {

        /*@
          loop invariant index + 1 <= j <= num;
          loop invariant ret >= 0; // Ensure ret remains non-negative.
          loop assigns j, ret;
          loop variant num - j;
        */
        for (int j = index + 1; j < num; j++) {
            if (array[index] + array[j] == p) {
                ret++;
            }
        }

    }
    return ret;
}
