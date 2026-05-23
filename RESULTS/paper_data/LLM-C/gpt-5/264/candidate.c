const char * seqLinear(int * seqNums, int seqNums_len);

/*@ predicate linear_seq{L}(int *a, integer n) =
      n <= 1 ? \true :
      (\forall integer i; 1 <= i < n ==> ((integer)a[i] - (integer)a[i-1]) == ((integer)a[1] - (integer)a[0]));
*/

/*@
  requires seqNums_len >= 1;
  requires seqNums_len == 1 || \valid_read(seqNums + (0 .. seqNums_len-1));
  assigns \nothing;
  ensures (\result == "Linear Sequence" || \result == "Non Linear Sequence");
  ensures (\result == "Linear Sequence") <==> linear_seq(seqNums, seqNums_len);
*/
const char * seqLinear(int * seqNums, int seqNums_len) {

        if (seqNums_len == 1)
            return "Linear Sequence";

        int difference = seqNums[1] - seqNums[0];

        /*@
          loop invariant 1 <= i <= seqNums_len;
          loop invariant difference == seqNums[1] - seqNums[0];
          loop invariant \forall integer k; 1 <= k < i ==> (seqNums[k] - seqNums[k-1] == difference);
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
