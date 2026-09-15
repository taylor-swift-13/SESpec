
/*@
*/

const char * foo264(int * seqNums, int seqNums_len) {

        if (seqNums_len == 1)
            return "Linear Sequence";

        int difference = seqNums[1] - seqNums[0];

        /* >>> LOOP INVARIANT TO FILL <<< */
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
