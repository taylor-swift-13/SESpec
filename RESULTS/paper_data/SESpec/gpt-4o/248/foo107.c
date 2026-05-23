
/*@
  logic integer count_greater_pairs(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : count_greater_pairs(a, lo + 1, hi) +
               (\sum integer j; lo + 1 <= j < hi && a[lo] > a[j] ? 1 : 0);
*/

/*@
  requires \valid(args + (0 .. args_len - 1));
  requires 0 <= num <= args_len;
  ensures \result >= 0;
  ensures \result == count_greater_pairs(args, 0, num);
*/
int foo107(int * args, int args_len, int num) {

    int ret = 0;

    /*@
      loop invariant 0 <= index <= num;
      loop invariant ret >= 0;
      loop invariant ret == count_greater_pairs(args, 0, index);
      loop invariant num == \at(num, Pre);
      loop invariant args_len == \at(args_len, Pre);
      loop invariant args == \at(args, Pre);
      loop assigns index, ret;
    */
    for (int index = 0; index < num; index++) {
        
        /*@
          loop invariant index + 1 <= c <= num;
          loop invariant ret >= 0;
          loop invariant ret == count_greater_pairs(args, 0, index) +
                                (\sum integer j; index + 1 <= j < c && args[index] > args[j] ? 1 : 0);
          loop assigns c, ret;
        */
        for (int c = index + 1; c < num; c++) {
            if (args[index] > args[c]) {
                ret++;
            }
        }
    }
    return ret;
}
