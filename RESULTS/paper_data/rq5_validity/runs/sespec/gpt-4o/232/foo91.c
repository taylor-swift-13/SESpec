
/*@ 
  logic integer count_unique_pairs(int* pairs, integer len) = 
    \sum(0, len - 1, 
         \lambda integer i; 
         \sum(i + 1, len - 1, 
              \lambda integer j; pairs[i] != pairs[j] ? 1 : 0));
*/

/*@ 
  requires \valid(pairs + (0 .. pairs_len - 1)); // Ensure pairs is a valid array
  requires pairs_len >= 0; // Ensure pairs_len is non-negative
  assigns \nothing;
*/
int foo91(int *pairs, int pairs_len, int array) {
    int count = 0;
    int total = pairs_len;

    /*@
                                   \sum(i + 1, total - 1, 
                                        \lambda integer j; pairs[i] != pairs[j] ? 1 : 0));
      loop assigns index, count;
      loop variant total - index; // Ensure termination
    */
    for (int index = 0; index < total - 1; index++) {
        /*@
          loop invariant index + 1 <= c <= total; // Strengthened bounds
                                       \sum(i + 1, total - 1, 
                                            \lambda integer j; pairs[i] != pairs[j] ? 1 : 0))
                                  + \sum(index + 1, c - 1, 
                                         \lambda integer j; pairs[index] != pairs[j] ? 1 : 0);
          loop assigns c, count;
          loop variant total - c; // Ensure termination
        */
        for (int c = index + 1; c < total; c++) {
            if (pairs[index] != pairs[c]) {
                count++;
            }
        }
    }

    return count;
}
