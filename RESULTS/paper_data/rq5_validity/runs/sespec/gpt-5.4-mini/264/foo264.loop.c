
const char * foo264(int * seqNums, int seqNums_len) {

        if (seqNums_len == 1)
            return "Linear Sequence";

        int difference = seqNums[1] - seqNums[0];

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i;
          loop invariant difference == seqNums[1] - seqNums[0];
          loop invariant \forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[k - 1] == difference;
          loop invariant \forall integer k; 0 <= k < seqNums_len ==> seqNums[k] == \at(seqNums[k], Pre);
          loop invariant (i <= seqNums_len) ==> (\forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[k - 1] == difference);
          loop invariant (i == 1) || (\exists integer k; 1 <= k < i && seqNums[k] - seqNums[k - 1] == difference);

          loop invariant (!(i < seqNums_len)) ==> (\forall integer k; 1 <= k < seqNums_len ==> seqNums[k] - seqNums[k - 1] == difference);
          loop assigns i;
            */
            for (int i = 1; i < seqNums_len; i++) {
            if (seqNums[i] - seqNums[i - 1] != difference) {
                return "Non Linear Sequence";
            }
        }
            
        return "Linear Sequence";
}
