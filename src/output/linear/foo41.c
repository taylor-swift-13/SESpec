
/*@
    requires n > 0;
*/
void foo41(int n) {
    int c = 0;

    /*@
        loop invariant ((c == 0)&&(n == \at(n,Pre))) || ((1 <= c <= n) || c == 1);
        loop invariant n == \at(n,Pre);
        loop assigns c;
    */
    while (unknown()) {
        if (unknown()) {
            if (c > n) {
                c = c + 1;
            }
        } else {
            if (c == n) {
                c = 1;
            }
        }
    }

    /*@ assert (c != n) ==> (c <= n); */
}
