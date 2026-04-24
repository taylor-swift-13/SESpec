int ncrModP(int n, int r, int p);

int ncrModP(int n, int r, int p) {

        if (n < r) {
            return 0;
        }

        int ncr = 1;
        for (int i = 1; i <= r; i++) {
            ncr = (ncr * (n - i + 1)) / i;
        }

        return ncr % p;
}
