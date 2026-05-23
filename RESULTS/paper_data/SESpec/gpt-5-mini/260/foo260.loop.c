
/*@
  requires \valid_read(args + (0 .. args_len-1));
  requires args_len >= 0;
*/
int foo260(int * args, int args_len, int array) {

    int ret = 0;
    int stop = array - 1;
    
    /*@
      loop invariant 0 <= ret;

      loop invariant \forall integer k; 0 <= k < \at(array,Pre) ==> args[k] == \at(args[k],Pre);

      loop invariant array == \at(array,Pre);
      loop invariant args_len == \at(args_len,Pre);
      loop invariant args == \at(args,Pre);

      loop assigns ret, stop;
    */
    while (ret <= stop) {
        int i = ret + (stop - ret) / 2;
        if (args[i] == i) {
            return i;
        } else if (args[i] < i) {
            ret = i + 1;
        } else {
            stop = i - 1;
        }
    }

    return -1;
}
