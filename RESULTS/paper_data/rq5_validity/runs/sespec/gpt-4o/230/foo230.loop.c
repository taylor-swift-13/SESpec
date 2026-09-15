
/*@
  logic integer count_pairs(int* pairs, integer lo, integer hi) =
    lo >= hi ? 0
             : count_pairs(pairs, lo, hi - 1) + (pairs[hi - 1] != pairs[lo] ? 1 : 0);
*/

/*@
  requires \valid(pairs + (0 .. pairs_len - 1));
  requires pairs_len >= 0;
  ensures \result >= 0;
*/

int foo230(int * pairs, int pairs_len, int array) {

    int count = 0;
    int total = pairs_len;

    /*@
      loop invariant 0 <= index <= total;
      loop invariant count >= 0;
      loop invariant total == \at(pairs_len, Pre);
      loop invariant array == \at(array, Pre);
      loop invariant pairs_len == \at(pairs_len, Pre);
      loop invariant pairs == \at(pairs, Pre);
      loop assigns index, count;
    */
    for (int index = 0; index < total - 1; index++) {

        /*@
          loop invariant index + 1 <= k <= total;
          loop invariant count >= 0;
          loop invariant \forall integer i, j; 0 <= i <= index && i < j < k ==> pairs[i] != pairs[j] || count >= 0;
          loop assigns k, count;
        */
        for (int k = index + 1; k < total; k++) {
            if (pairs[index] != pairs[k]) {
                count++;
            }
        }
    }

    return count;
}
