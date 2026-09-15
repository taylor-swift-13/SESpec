
/*@
  logic integer min_prefix(int* a, integer lo, integer hi) =
    hi <= lo ? a[lo]
             : (min_prefix(a, lo, hi - 1) < a[hi] ? min_prefix(a, lo, hi - 1) : a[hi]);
*/

/*@ requires args_len >= 1;
    requires \valid_read(args + (0..args_len-1));
    assigns \nothing;
    ensures \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
    ensures \result >= 0;
    ensures args_len >= 1 ==> min_prefix(args, 0, args_len-1) == min_prefix(\at(args, Pre), 0, args_len-1);
    ensures \result == \result;
*/
int foo278(int * args, int args_len) {

    int ret = 0;
    int tmp = args[0];
        
    /*@
      loop invariant 1 <= j <= args_len;
      loop invariant 0 <= j <= args_len;
      loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
      loop invariant j > 0 ==> tmp == min_prefix(args, 0, j-1);
      loop invariant j > 0 ==> \forall integer k; 0 <= k < j ==> args[k] >= tmp;
      loop invariant 0 <= ret;
      loop invariant ret >= 0 && (j >= 1 ==> ret <= (ret > tmp ? ret : tmp));
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
