

/*@
  requires seqNums_len >= 0;
  requires \valid(&seqNums[0] + (0..seqNums_len-1));
  requires \forall integer i; 0 <= i < seqNums_len ==> 0 <= seqNums[i] <= 100;
  assigns \nothing;
  ensures \forall integer i; 0 <= i < seqNums_len ==> seqNums[i] == \old(seqNums[i]);
  ensures seqNums_len == 1 ==> \result != \null;
  ensures seqNums_len >= 2 &&
          (\forall integer k; 1 <= k < seqNums_len ==> seqNums[k] - seqNums[k-1] == seqNums[1] - seqNums[0])
          ==> \result != \null;
  ensures seqNums_len >= 2 &&
          (\exists integer k; 1 <= k < seqNums_len && seqNums[k] - seqNums[k-1] != seqNums[1] - seqNums[0])
          ==> \result != \null;
  ensures \result != \null;
*/
const char * foo264(int * seqNums, int seqNums_len) {

        if (seqNums_len == 1)
            return "Linear Sequence";

        int difference = seqNums[1] - seqNums[0];

        /*@
          loop invariant i >= 1;
          loop invariant difference == seqNums[1] - seqNums[0];
          loop invariant \forall integer k; 1 <= k < i ==> seqNums[k] - seqNums[k - 1] == difference;
          loop invariant \forall integer k; 0 <= k < seqNums_len ==> seqNums[k] == \at(seqNums[k], Pre);
          loop invariant (!(i < seqNums_len)) ==> (\forall integer k; 1 <= k < seqNums_len ==> seqNums[k] - seqNums[k - 1] == difference);
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
