int ncrModP(int n, int r, int p);

/* 2. FUNC CONTRACT */
int ncrModP(int n, int r, int p) {

        if (n < r) {
            return 0;
        }

        int ncr = 1;
        /* 1. LOOP INVARIANT */
        for (int i = 1; i <= r; i++) {
            ncr = (ncr * (n - i + 1)) / i;
        }

        return ncr % p;
}
