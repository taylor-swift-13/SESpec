
/*@
  requires args_len >= 1;
  requires \valid_read(args + (0..args_len-1));
  assigns \nothing;
  ensures \forall integer k; 0 <= k < args_len ==> args[k] == \old(args[k]);
  ensures \result >= 0;
*/
int foo279(int * args, int args_len) {

    int g = 0;
    int ret = args[0];
        
    /*@
      loop invariant 1 <= j;
      loop invariant j <= args_len;
      loop invariant 0 <= g;
      loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
      loop invariant \forall integer k; 0 <= k < j ==> ret <= args[k];
      loop invariant \exists integer k; 0 <= k < j && ret == args[k];
      loop assigns j, g, ret;
    */
    for (int j = 1; j < args_len; j++) {
        if (args[j] > ret) {
            g = g > ret ? g : ret;
        } else {
            ret = args[j];
        }
    }
        
    return g;
}
