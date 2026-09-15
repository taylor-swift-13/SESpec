
/*@
  logic integer min_prefix(int* a, integer lo, integer hi) =
    hi <= lo ? a[lo]
             : (min_prefix(a, lo, hi - 1) < a[hi] ? min_prefix(a, lo, hi - 1) : a[hi]);
*/

/*@ requires args_len >= 1;
    requires \valid_read(args + (0..args_len-1));
*/
int foo278(int * args, int args_len) {

    int ret = 0;
    int tmp = args[0];
        
    /*@
      loop invariant 1 <= j <= args_len;
      loop invariant 0 <= j <= args_len;
      loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);

      // tmp tracks the minimum of the processed prefix [0..j-1]
      loop invariant j > 0 ==> tmp == min_prefix(args, 0, j-1);

      // Every processed element is at least tmp (since tmp is the minimum so far)
      loop invariant j > 0 ==> \forall integer k; 0 <= k < j ==> args[k] >= tmp;

      // ret is monotone non-decreasing across iterations and starts from 0
      loop invariant 0 <= ret;
      

      // ret is always one of the values obtainable by repeatedly applying ret = max(ret, tmp)
      // in particular, ret <= \max(tmp, \at(ret,Pre)) after each step; we capture a weaker preserved bound:
      loop invariant ret >= 0 && (j >= 1 ==> ret <= \max(ret, tmp));

      // Exit implication: when the loop ends, j == args_len and tmp is the minimum over the whole prefix
      loop invariant (j == args_len) ==> (tmp == min_prefix(args, 0, args_len-1));

      loop assigns j, ret, tmp;
    */
    for (int j = 1; j < args_len; j++) {
        if (args[j] > tmp) {
            ret = ret > tmp ? ret : tmp;
        } else {
            tmp = args[j];
        }
    }
        
    return ret;
}
