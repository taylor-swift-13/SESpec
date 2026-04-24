int binomialCoeff(int n, int k);

int binomialCoeff(int n, int k) {

        if (k > n - k)
            k = n - k;
        int c = 1;
        for (int i = 1; i <= k; i++) {
            c = c * (n - i + 1) / i;
        }
        return c;
}
