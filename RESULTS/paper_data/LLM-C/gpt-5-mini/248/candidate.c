int getInvCount(int * args, int args_len, int num);

/*@
    requires 0 <= num <= args_len;
    requires \valid(args + (0 .. num-1));
    assigns \nothing;
    ensures 0 <= \result <= num*(num-1)/2;
    ensures \result == \sum integer i; 0 <= i < num;
                        (\sum integer j; i+1 <= j < num;
                            (args[i] > args[j]) ? 1 : 0);
*/
int getInvCount(int * args, int args_len, int num) {

        int ret = 0;

        /*@
            loop invariant 0 <= index <= num;
            loop invariant 0 <= ret <= num*(num-1)/2;
            loop invariant ret == (\sum integer i; 0 <= i < index;
                                        (\sum integer j; i+1 <= j < num;
                                            (args[i] > args[j]) ? 1 : 0));
            loop assigns index, ret;
            loop variant num - index;
        */
        for (int index = 0; index < num; index++) {
            /*@
                loop invariant index >= 0 && index < num;
                loop invariant index+1 <= c <= num;
                loop invariant 0 <= ret <= num*(num-1)/2;
                loop invariant ret == 
                    (\sum integer i; 0 <= i < index;
                        (\sum integer j; i+1 <= j < num;
                            (args[i] > args[j]) ? 1 : 0))
                    + (\sum integer j; index+1 <= j < c;
                            (args[index] > args[j]) ? 1 : 0);
                loop assigns c, ret;
                loop variant num - c;
            */
            for (int c = index + 1; c < num; c++) {
                if (args[index] > args[c]) {
                    ret++;
                }
            }
        }
        return ret;
}
