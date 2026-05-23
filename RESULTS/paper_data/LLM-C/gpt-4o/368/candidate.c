/*@
    requires n >= 0 && r >= 0 && p > 0;
    requires r <= n;
    ensures \result >= 0 && \result < p;
    assigns \nothing;
*/
int ncrModP(int n, int r, int p);

int ncrModP(int n, int r, int p) {

        if (n < r) {
            return 0;
        }

        int ncr = 1;
        /*@
            loop invariant 1 <= i <= r + 1;
            loop invariant ncr >= 0;
            loop invariant ncr == \prod{j=1..i-1} ((n - j + 1) / j);
            loop assigns i, ncr;
            loop variant r - i;
        */
        for (int i = 1; i <= r; i++) {
            ncr = (ncr * (n - i + 1)) / i;
        }

        return ncr % p;
}
