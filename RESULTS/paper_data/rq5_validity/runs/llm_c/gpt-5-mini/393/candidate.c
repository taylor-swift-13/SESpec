int lastTwoDigits(int num);

/*@
    requires num >= 0;
    assigns \nothing;
    ensures 0 <= \result < 100;
    ensures \result == (\product integer i; 1 <= i <= num; i) % 100;
*/
int lastTwoDigits(int num) {

        int ret = 1;
        /*@
            loop invariant 1 <= loop <= num+1;
            loop invariant ret == (\product integer i; 1 <= i < loop; i);
            loop assigns loop, ret;
            loop variant num - loop + 1;
        */
        for (int loop = 1; loop <= num; loop++) {
            ret *= loop;
        }
        int remainder = (int) (ret % 100);
        return remainder;
}
