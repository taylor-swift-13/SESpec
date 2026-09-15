
/*@
    requires 0 <= num;
    requires \valid_read(args + (0 .. num-1));
    assigns \nothing;
    ensures 0 <= \result;
    ensures \result <= num * (num - 1) / 2;
*/
int foo246(int *args, int args_len, int num)
{
    int ret = 0;

    /*@
        loop invariant 0 <= index <= num;
        loop invariant 0 <= ret;
        loop invariant ret <= index * (2 * num - index - 1) / 2;
        loop assigns ret, index;
        loop variant num - index;
    */
    for (int index = 0; index < num; index++) {

        /*@
            loop invariant index + 1 <= k <= num;
            loop invariant 0 <= ret;
            loop invariant ret <= index * (2 * num - index - 1) / 2 + (k - (index + 1));
            loop assigns ret, k;
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
