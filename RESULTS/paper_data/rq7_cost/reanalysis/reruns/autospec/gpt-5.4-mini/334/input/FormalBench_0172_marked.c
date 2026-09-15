int difference(int n);

/* 3. FUNC CONTRACT */
int difference(int n) {

        int sum = 0;
        int sum1 = 0;
        /* 1. LOOP INVARIANT */
        for (int i = 1; i <= n; i++) {
            sum += i * i * i;
        }
        /* 2. LOOP INVARIANT */
        for (int i = 1; i <= n; i++) {
            sum1 += i;
        }
        return sum - sum1;
}
