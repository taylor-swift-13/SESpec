int permutationCoefficient(int n, int k);

/* 2. FUNC CONTRACT */
int permutationCoefficient(int n, int k) {

        int res = 1;
        int i = 1;
        /* 1. LOOP INVARIANT */
        while (i <= k) {
            res *= (n - i + 1);
            i++;
        }
        return res;
}
