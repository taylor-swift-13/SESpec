
/*@
  logic integer diff(int* seqNums, integer lo, integer hi) =
    lo >= hi ? 0 : seqNums[lo + 1] - seqNums[lo];
*/

/*@
  predicate is_linear_sequence(int* seqNums, integer len, integer diff) =
    \forall integer i; 1 <= i < len ==> seqNums[i] - seqNums[i - 1] == diff;
*/

/*@
  requires \valid(&seqNums[0] + (0..seqNums_len-1));
  requires \forall integer i; 0 <= i < seqNums_len ==> 0 <= seqNums[i] <= 100;
  requires seqNums_len > 0;
  requires seqNums_len < 100;
  assigns \nothing;
*/
const char * foo139(int * seqNums, int seqNums_len) {

    if (seqNums_len == 1)
        return "Linear Sequence";

    int difference = seqNums[1] - seqNums[0];

    /*@
      loop invariant 1 <= i <= seqNums_len;
      loop invariant \forall integer k; 0 <= k < seqNums_len ==> seqNums[k] == \at(seqNums[k], Pre);
      loop invariant \forall integer j; 1 <= j < i ==> seqNums[j] - seqNums[j - 1] == difference;
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
