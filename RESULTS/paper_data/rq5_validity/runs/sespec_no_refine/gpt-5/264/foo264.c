
/*@
  // No additional predicates or logic functions are required.
*/

/*@
  requires \valid(&seqNums[0] + (0..seqNums_len-1));
  requires \forall integer i; 0 <= i < seqNums_len ==> 0 <= seqNums[i] <= 100;
  requires seqNums_len > 0;
  requires seqNums_len < 100;
  assigns \nothing;
  ensures (\result == "Linear Sequence") <==>
          (\forall integer k; 1 <= k < seqNums_len ==> seqNums[k] - seqNums[k - 1] == seqNums_len == 1 ? 0 : seqNums[1] - seqNums[0]);
  ensures (\result == "Non Linear Sequence") <==>
          (\exists integer k; 1 <= k < seqNums_len && seqNums[k] - seqNums[k - 1] != (seqNums_len == 1 ? 0 : seqNums[1] - seqNums[0]));
  ensures \result == "Linear Sequence" || \result == "Non Linear Sequence";
*/
const char * foo264(int * seqNums, int seqNums_len) {

        if (seqNums_len == 1)
            return "Linear Sequence";

        int difference = seqNums[1] - seqNums[0];

        /*@
          loop invariant 1 <= i <= seqNums_len;
          loop invariant \forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[k - 1] == difference;
          loop invariant \forall integer k; 0 <= k < seqNums_len ==> seqNums[k] == \at(seqNums[k], Pre);
          loop assigns i;
        */
            /*@
          loop invariant 1 <= i <= seqNums_len;
          loop invariant \forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[k - 1] == difference;
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
