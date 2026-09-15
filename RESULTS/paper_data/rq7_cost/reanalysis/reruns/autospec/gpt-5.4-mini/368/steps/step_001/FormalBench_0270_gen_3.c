int ncrModP(int n, int r, int p);

int ncrModP(int n, int r, int p) {

        if (n < r) {
            return 0;
        }

        int ncr = 1;
        /*@
        loop invariant 0 <= i <= r + 1;
        loop invariant ncr >= 1;
        loop invariant \forall integer k; 1 <= k < i ==> ncr == (((1 * (n - 1 + 1)) / 1) * (n - 2 + 1) / 2);
        loop assigns i;
        loop assigns ncr;
        */
        for (int i = 1; i <= r; i++) {
            ncr = (ncr * (n - i + 1)) / i;
        }

        return ncr % p;
}
