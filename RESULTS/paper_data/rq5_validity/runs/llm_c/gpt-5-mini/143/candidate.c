/*@
    requires n >= 2;
    requires time >= 0;
    assigns \nothing;
    ensures 1 <= \result <= n;
    ensures (time % ((n - 1) * 2)) < n ==> \result == (time % ((n - 1) * 2)) + 1;
    ensures (time % ((n - 1) * 2)) >= n ==> \result == 2 * n - (time % ((n - 1) * 2)) - 1;
*/
int passPillow(int n, int time);

int passPillow(int n, int time) {

        time %= (n - 1) * 2;
        return time < n ? time + 1 : n * 2 - time - 1;
}
