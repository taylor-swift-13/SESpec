/*@
    requires n > 1;
    requires time >= 0;
    ensures 1 <= \result <= n;
    assigns \nothing;
*/
int passPillow(int n, int time) {

        time %= (n - 1) * 2;
        return time < n ? time + 1 : n * 2 - time - 1;
}
