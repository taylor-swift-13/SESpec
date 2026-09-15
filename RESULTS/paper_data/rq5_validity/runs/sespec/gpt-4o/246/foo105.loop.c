
/*@
  // No additional predicate or logic function needed for this example
*/

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
*/

int foo105(int * args, int args_len, int num) {

    int ret = 0;

    /*@
      loop invariant 0 <= index <= num;
      loop invariant 0 <= ret <= index * (num - index - 1) / 2;
      loop invariant \forall integer i, j; 0 <= i < index && index < j < num ==> args[i] <= args[j];
      loop invariant num == \at(num,Pre);
      loop invariant args_len == \at(args_len,Pre);
      loop invariant args == \at(args,Pre);
      loop assigns index, ret;
    */
    for (int index = 0; index < num; index++) {
        
        /*@
          loop invariant index + 1 <= k <= num;
          loop invariant 0 <= ret <= index * (num - index - 1) / 2;
          loop invariant \forall integer i, j; 0 <= i < index && index < j < num ==> args[i] <= args[j];
          loop invariant num == \at(num,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
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
