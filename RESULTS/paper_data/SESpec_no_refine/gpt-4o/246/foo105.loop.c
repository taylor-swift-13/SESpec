
/*@
  logic integer count_greater_pairs(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : count_greater_pairs(a, lo + 1, hi) +
               (\sum integer k; lo < k < hi && a[lo] > a[k] ? 1 : 0);
*/

/*@
  requires \valid(args + (0 .. args_len - 1));
  requires 0 <= num <= args_len;
  ensures \result >= 0;
  ensures \result == count_greater_pairs(args, 0, num);
*/
int foo105(int * args, int args_len, int num) {

    int ret = 0;

    /*@
      loop invariant 0 <= index <= num;
      loop invariant ret >= 0;
      loop invariant ret == count_greater_pairs(args, 0, index);
      loop assigns index, ret;
    */
    for (int index = 0; index < num; index++) {

        /*@
          loop invariant index + 1 <= k <= num;
          loop invariant ret >= 0;
          loop invariant ret == count_greater_pairs(args, 0, index) +
                                (\sum integer j; index + 1 <= j < k && args[index] > args[j] ? 1 : 0);
          loop assigns k, ret;
        */
        for (int k = index + 1; k < num; k++) {
            if (args[index] > args[k]) {
                ret++;
            }
        }

    }
    return ret;
}
