int getInvCount(int * args, int args_len, int num);

 /*@
    requires args != \null;
    requires 0 <= args_len;
    requires 0 <= num <= args_len;
    requires \valid(args + (0 .. args_len-1));
    assigns \nothing;
    ensures 0 <= \result <= num*(num-1)/2;
    ensures \result == (\sum integer i; 0 <= i < num;
                          (\sum integer k; i+1 <= k < num;
                             (args[i] > args[k] ? 1 : 0)));
 */
int getInvCount(int * args, int args_len, int num) {

        int ret = 0;

        /*@
            loop invariant 0 <= index <= num;
            loop invariant ret == (\sum integer i; 0 <= i < index;
                                      (\sum integer k; i+1 <= k < num;
                                         (args[i] > args[k] ? 1 : 0)));
            loop assigns index, ret;
            loop variant num - index;
        */
        for (int index = 0; index < num; index++) {
                /*@
                    loop invariant index+1 <= k <= num;
                    loop invariant ret == (\sum integer i; 0 <= i < index;
                                              (\sum integer kk; i+1 <= kk < num;
                                                 (args[i] > args[kk] ? 1 : 0)))
                                     + (\sum integer kk; index+1 <= kk < k;
                                          (args[index] > args[kk] ? 1 : 0));
                    loop assigns k, ret;
                    loop variant num - k;
                */
                for (int k = index + 1; k < num; k++) {
                        if (args[index] > args[k]) {
                                ret++;
                        }
                }
        }
        return ret;
}
