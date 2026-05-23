/*@
    requires n > 1;
    requires time >= 0;
    ensures 1 <= \result <= n;
    assigns \nothing;
*/
int passPillow(int n, int time) {

    /*@
        assigns time;
        ensures time == \old(time) % (n - 1) * 2;
    */
    time = time % (n - 1) * 2;

    if (time < n) {
        /*@
            ensures \result == time + 1;
        */
        return time + 1;
    }

    /*@
        ensures \result == n * 2 - time - 1;
    */
    return n * 2 - time - 1;
}
