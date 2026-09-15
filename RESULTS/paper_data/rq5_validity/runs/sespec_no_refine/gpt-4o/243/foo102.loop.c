
/*@
  // Predicate to define valid array bounds
  predicate valid_bounds(int *arr, integer len) = \valid(arr + (0 .. len - 1));
*/

/*@
  // Logic function to count the number of pairs (i, j) such that pairs[i] + pairs[j] == p
  logic integer count_pairs(int* pairs, integer len, integer p) =
    (len <= 1) ? 0 :
    count_pairs(pairs, len - 1, p) +
    (\exists integer j; 0 <= j < len - 1 && pairs[len - 1] + pairs[j] == p ? 1 : 0);
*/

/*@
  requires valid_bounds(pairs, pairs_len);
  requires 0 <= num <= pairs_len;
  ensures \result >= 0;
  ensures \result == count_pairs(pairs, num, p);
*/
int foo102(int * pairs, int pairs_len, int num, int p) {

    int result = 0;
    /*@
      loop invariant 0 <= index <= num;
      loop invariant result >= 0;
      loop invariant result == count_pairs(pairs, index, p);
      loop invariant valid_bounds(pairs, pairs_len);
      loop invariant 0 <= num <= pairs_len;
      loop assigns index, result;
      loop variant num - index;
    */
    for (int index = 0; index < num; index++) {

        /*@
          loop invariant index + 1 <= j <= num;
          loop invariant result >= 0;
          loop invariant result == count_pairs(pairs, index, p) +
                                   (\sum integer k; index + 1 <= k < j && pairs[index] + pairs[k] == p ? 1 : 0);
          loop invariant valid_bounds(pairs, pairs_len);
          loop invariant 0 <= num <= pairs_len;
          loop assigns j, result;
          loop variant num - j;
        */
        for (int j = index + 1; j < num; j++) {
            if (pairs[index] + pairs[j] == p) {
                result++;
            }
        }

    }
    return result;
}
