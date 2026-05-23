
/*@
  logic integer pair_count(int* array, integer lo, integer hi, integer p) =
    lo >= hi ? 0
             : pair_count(array, lo, hi - 1, p) +
               (\exists integer j; lo <= j < hi && array[lo] + array[j] == p ? 1 : 0);
*/

/*@
  requires \valid(array + (0 .. array_len - 1));
  requires array_len >= 0;
  requires num >= 0 && num <= array_len;
  ensures \result >= 0;
  ensures \result == pair_count(array, 0, num, p);
  assigns \nothing;
*/
int foo103(int * array, int array_len, int num, int p) {

    int ret = 0;
    /*@
      loop invariant 0 <= index <= num;
      loop invariant ret >= 0;
      loop invariant ret == pair_count(array, 0, index, p);
      loop invariant \forall integer i, j; 0 <= i < index && i < j < num ==> array[i] + array[j] != p;
      loop assigns index, ret;
    */
    for (int index = 0; index < num; index++) {

        /*@
          loop invariant index + 1 <= j <= num;
          loop invariant ret >= 0;
          loop invariant ret == pair_count(array, 0, index, p) + pair_count(array + index + 1, 0, j - (index + 1), p - array[index]);
          loop invariant \forall integer k, l; 0 <= k < index && k < l < num ==> array[k] + array[l] != p;
          loop invariant \forall integer l; index + 1 <= l < j ==> array[index] + array[l] != p;
          loop assigns j, ret;
        */
        for (int j = index + 1; j < num; j++) {
            if (array[index] + array[j] == p) {
                ret++;
            }
        }

    }
    return ret;
}
