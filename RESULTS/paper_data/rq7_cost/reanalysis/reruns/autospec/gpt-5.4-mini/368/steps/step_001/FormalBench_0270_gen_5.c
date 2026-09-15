int ncrModP(int n, int r, int p);

int ncrModP(int n, int r, int p) {

        if (n < r) {
            return 0;
        }

        int ncr = 1;
        /*@
        loop invariant 1 <= i <= r + 1;
        loop invariant ncr >= 1;
        loop invariant ncr == \at(ncr, Pre);
        loop assigns i;
        loop assigns ncr;
        */
        for (int i = 1; i <= r; i++) {
            ncr = (ncr * (n - i + 1)) / i;
        }

        return ncr % p;
}
