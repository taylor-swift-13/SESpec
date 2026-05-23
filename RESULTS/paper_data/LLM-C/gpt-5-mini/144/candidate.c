int passPillow(int n, int time);

/*@
    requires n >= 2;
    requires time >= 0;
    assigns \nothing;
    ensures 1 <= \result <= n;
    ensures \result == (((time % (n - 1)) * 2) < n ? ((time % (n - 1)) * 2) + 1 : (n * 2) - ((time % (n - 1)) * 2) - 1);
*/
int passPillow(int n, int time) {

        time = time % (n - 1) * 2;
        if (time < n) {
            return time + 1;
        }
        return n * 2 - time - 1;
}
