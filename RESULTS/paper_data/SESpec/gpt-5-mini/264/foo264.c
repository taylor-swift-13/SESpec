
/*@
  predicate prefix_same_diff(int* a, integer len, integer i, integer d) =
    (i >= 1 && i <= len) ==> (\forall integer k; 1 <= k < i ==> a[k] - a[k-1] == d);
*/

/*@
  predicate is_linear_sequence(int* a, integer len) =
    len == 1
    ||
    (len >= 2 && (\forall integer i; 1 <= i && i < len ==> a[i] - a[i-1] == a[1] - a[0]));
*/
/*@
  requires seqNums_len >= 0;
  requires seqNums_len == 0 || \valid_read(seqNums + (0 .. seqNums_len-1));
  assigns \nothing;
  ensures \forall integer k; 0 <= k < seqNums_len ==> seqNums[k] == \at(seqNums[k], Pre);
*/
const char * foo264(int * seqNums, int seqNums_len) {

        if (seqNums_len == 1)
            return "Linear Sequence";

        int difference = seqNums[1] - seqNums[0];

        /*@
          loop invariant (i < seqNums_len) ==> (1 <= i && i <= seqNums_len);
          loop invariant (i < seqNums_len) ==> (\forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[k-1] == difference);
          loop invariant \forall integer k; 0 <= k < seqNums_len ==> seqNums[k] == \at(seqNums[k], Pre);
          loop assigns i;
        */
        for (int i = 1; i < seqNums_len; i++) {
            if (seqNums[i] - seqNums[i - 1] != difference) {
                return "Non Linear Sequence";
            }
        }

        return "Linear Sequence";
}
