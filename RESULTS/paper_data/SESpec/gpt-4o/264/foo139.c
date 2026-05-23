
/*@
  logic integer diff(int* seqNums, integer i) =
    i <= 0 ? 0 : seqNums[i] - seqNums[i - 1];
*/

/*@
  predicate is_linear_sequence(int* seqNums, integer len, integer difference) =
    len <= 1 || (\forall integer i; 1 <= i < len ==> seqNums[i] - seqNums[i - 1] == difference);
*/

/*@
  requires \valid(seqNums + (0..seqNums_len-1));
  requires seqNums_len > 0;
  assigns \nothing;
*/
const char * foo139(int * seqNums, int seqNums_len) {

    if (seqNums_len == 1)
        return "Linear Sequence";

    int difference = seqNums[1] - seqNums[0];

    /*@
      loop invariant 1 <= i <= seqNums_len;
      loop invariant \forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[k - 1] == difference;
      loop invariant \valid(seqNums + (0..seqNums_len-1));
      loop assigns i;
      loop variant seqNums_len - i;
    */
    for (int i = 1; i < seqNums_len; i++) {
        if (seqNums[i] - seqNums[i - 1] != difference) {
            return "Non Linear Sequence";
        }
    }

    return "Linear Sequence";
}
