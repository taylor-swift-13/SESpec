/*@
    requires seqNums_len >= 1;
    requires \valid(seqNums + (0 .. seqNums_len - 1));
    assigns \nothing;
    ensures \result == "Linear Sequence" || \result == "Non Linear Sequence";
    behavior len1:
        assumes seqNums_len == 1;
        ensures \result == "Linear Sequence";
    behavior len_gt1:
        assumes seqNums_len > 1;
        ensures (\result == "Linear Sequence") <==> (\forall integer i; 1 <= i < seqNums_len ==> seqNums[i] - seqNums[i-1] == seqNums[1] - seqNums[0]);
    complete behaviors len1, len_gt1;
    disjoint behaviors len1, len_gt1;
*/
const char * seqLinear(int * seqNums, int seqNums_len) {

        if (seqNums_len == 1)
            return "Linear Sequence";

        int difference = seqNums[1] - seqNums[0];

        /*@
            loop invariant 1 <= i <= seqNums_len;
            loop invariant \forall integer j; 1 <= j < i ==> seqNums[j] - seqNums[j-1] == difference;
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
