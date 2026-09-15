
/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires num >= 0;
*/

int foo248(int * args, int args_len, int num) {

    int ret = 0;

    /*@
      loop invariant 0 <= index && index <= num;
      loop invariant 0 <= ret;
      loop invariant (index < \at(num,Pre)) ==> (0 <= index && index < num);
      loop invariant (index < \at(num,Pre)) ==> (0 <= ret);
      loop invariant (!(index < \at(num,Pre))) ==> (index == num && num == \at(num,Pre) && args_len == \at(args_len,Pre) && args == \at(args,Pre));
      loop invariant num == \at(num,Pre);
      loop invariant args_len == \at(args_len,Pre);
      loop invariant args == \at(args,Pre);
      loop invariant \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
      loop assigns index, ret;
    */
    for (int index = 0; index < num; index++) {

        /*@
          loop invariant index + 1 <= c && c <= num;
          loop invariant 0 <= index && index <= num;
          loop invariant 0 <= ret;
          loop invariant (\forall int i; 0 <= i && i < index ==>
                          (\forall int j; i+1 <= j && j < num ==>
                             (args[i] > args[j] ? \true : \true)));
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
