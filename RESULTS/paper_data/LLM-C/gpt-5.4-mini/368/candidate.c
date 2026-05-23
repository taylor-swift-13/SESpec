/*@
    requires p > 0;
    requires 0 <= r;
    requires r <= n;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result < p;
*/
int ncrModP(int n, int r, int p);

 /*@
    requires p > 0;
    requires 0 <= r;
    assigns \nothing;
    ensures (n < r) ==> \result == 0;
    ensures (n >= r) ==> 0 <= \result < p;
*/
int ncrModP(int n, int r, int p) {

        if (n < r) {
            return 0;
        }

        int ncr = 1;
        /*@
            loop invariant 1 <= i <= r + 1;
            loop invariant ncr >= 1;
            loop assigns i, ncr;
            loop variant r - i + 1;
        */
        for (int i = 1; i <= r; i++) {
            ncr = (ncr * (n - i + 1)) / i;
        }

        return ncr % p;
}
