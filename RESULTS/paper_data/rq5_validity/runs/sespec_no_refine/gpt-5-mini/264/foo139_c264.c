
/*@
  logic boolean same_diffs(int* a, integer lo, integer hi, integer d) =
    lo >= hi ? \true
             : (a[lo] - a[lo-1] == d) && same_diffs(a, lo+1, hi, d);
*/

/*@
  requires \valid_read(seqNums + (0 .. seqNums_len-1));
  requires seqNums_len >= 0;
  assigns \nothing;   
*/
const char * foo139_c264(int * seqNums, int seqNums_len) {

        if (seqNums_len == 1)
            return "Linear Sequence";

        int difference = seqNums[1] - seqNums[0];

        /*@
          loop invariant \forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[k-1] == difference;
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
