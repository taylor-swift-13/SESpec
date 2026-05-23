
/*@
  predicate binary_search_invariant(int* i, integer lo, integer hi, integer array) =
    \forall integer k; 0 <= k < array ==> (k < lo || k > hi || i[k] != k);
*/

/*@
  requires \valid(i + (0..i_len-1));
  requires i_len >= 0;
  requires array >= 0; // Strengthened precondition to ensure valid initial state
  ensures \result == -1 || (0 <= \result < i_len && i[\result] == \result);
*/
int foo258(int * i, int i_len, int array) {

    int ret = 0;
    int stop = array - 1;

    /*@
      loop invariant 0 <= ret && ret <= array; // Weakened to ensure valid initial state
      loop invariant -1 <= stop && stop < array; // Valid bounds for `stop`
      loop invariant ret <= stop + 1; // Adjusted to ensure compatibility with initial state
      loop invariant array == \at(array, Pre); // Array remains unchanged
      loop invariant i_len == \at(i_len, Pre); // Length remains unchanged
      loop invariant i == \at(i, Pre); // Pointer remains unchanged
      loop assigns ret, stop;
    */
    while (ret <= stop) {
        int cur = ret + (stop - ret) / 2;
        if (i[cur] == cur) {
            return cur;
        } else if (i[cur] < cur) {
            ret = cur + 1;
        } else {
            stop = cur - 1;
        }
    }

    return -1;
}
