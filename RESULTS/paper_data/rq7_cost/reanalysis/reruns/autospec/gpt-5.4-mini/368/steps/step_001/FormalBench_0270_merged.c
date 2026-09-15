int ncrModP(int n, int r, int p);

int ncrModP(int n, int r, int p) {

        if (n < r) {
            return 0;
        }

        int ncr = 1;
        /*@
        loop invariant ncr == \numof(integer k; 1 <= k < i; ((n - k + 1) / k));
        loop invariant ncr == \numof int k; 1 <= k < i ==> (n - k + 1) / k;
        loop invariant ncr == \at(ncr, Pre);
        loop invariant ncr == 1;
        loop invariant i <= r + 1;
        loop invariant \forall integer k; 1 <= k < i ==> ncr >= (n - k + 1);
        loop invariant \forall integer k; 1 <= k < i ==> ncr > 0;
        loop invariant \forall integer k; 1 <= k < i ==> ncr == (((1 * (n - 1 + 1)) / 1) * (n - 2 + 1) / 2);
        loop invariant 1 <= ncr;
        loop invariant 1 <= i;
        loop invariant 0 <= i;
        loop assigns ncr;
        loop assigns i;
        */
        for (int i = 1; i <= r; i++) {
            ncr = (ncr * (n - i + 1)) / i;
        }

        return ncr % p;
}
