
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
  ensures \result >= 0;
  ensures \result == count_pairs(array, 0, num, p);
*/
int foo103(int * array, int array_len, int num, int p) {

    int ret = 0;

    /*@
      loop invariant 0 <= index <= num;
      loop assigns index, ret;
      loop variant num - index;
    */
    for (int index = 0; index < num; index++) {

        /*@
          loop invariant index + 1 <= j <= num;
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
