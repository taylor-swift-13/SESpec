/*@
    requires n > 1;
    requires time >= 0;
    assigns \nothing;
    ensures 1 <= \result <= n;
*/
int passPillow(int n, int time);

 /*@
    requires n > 1;
    requires time >= 0;
    assigns \nothing;
    ensures 1 <= \result <= n;
*/
int passPillow(int n, int time) {

        time = time % (n - 1) * 2;
        if (time < n) {
            return time + 1;
        }
        return n * 2 - time - 1;
}
