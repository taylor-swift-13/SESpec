
/*@
*/

/*@
  requires 1 <= seqNums_len;
  requires \valid_read(seqNums + (0..seqNums_len-1));
  assigns \nothing;
  ensures seqNums_len == 1 ==> \result == "Linear Sequence";
  ensures seqNums_len > 1 && (\forall integer i; 1 <= i < seqNums_len ==> seqNums[i] - seqNums[i - 1] == seqNums[1] - seqNums[0]) ==> \result == "Linear Sequence";
  ensures seqNums_len > 1 && (\exists integer i; 1 <= i < seqNums_len && seqNums[i] - seqNums[i - 1] != seqNums[1] - seqNums[0]) ==> \result == "Non Linear Sequence";
  ensures \result == \null ==> \false;
  ensures \result == "Linear Sequence" || \result == "Non Linear Sequence";
*/
const char * foo264(int * seqNums, int seqNums_len) {

        if (seqNums_len == 1)
            return "Linear Sequence";

        int difference = seqNums[1] - seqNums[0];

        /*@
          loop invariant 1 <= i <= seqNums_len;
          loop invariant \forall integer j; 1 <= j < i ==> seqNums[j] - seqNums[j - 1] == difference;
          loop assigns i;
        */
        for (int i = 1; i < seqNums_len; i++) {
            if (seqNums[i] - seqNums[i - 1] != difference) {
                return "Non Linear Sequence";
            }
        }
            
        return "Linear Sequence";
}
