/*@
    requires r >= 0;
    requires p > 0;
    assigns \nothing;
    ensures n < r ==> \result == 0;
    ensures n >= r ==>
        \result == (
            (
              (\product integer k; 1 <= k <= r; (n - k + 1))
              / 
              (\product integer k; 1 <= k <= r; k)
            ) % p
        );
    ensures 0 <= \result < p;
*/
int ncrModP(int n, int r, int p) {

        if (n < r) {
            return 0;
        }

        int ncr = 1;
        /*@
            loop invariant 1 <= i <= r + 1;
            loop invariant ncr == (
                (\product integer k; 1 <= k < i; (n - k + 1))
                /
                (\product integer k; 1 <= k < i; k)
            );
            loop assigns i, ncr;
            loop variant r - i + 1;
        */
        for (int i = 1; i <= r; i++) {
            ncr = (ncr * (n - i + 1)) / i;
        }

        return ncr % p;
}
