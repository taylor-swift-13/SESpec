int averageOdd(int n);

/* 2. FUNC CONTRACT */
int averageOdd(int n) {

        int sum = 0;
        int count = 0;
        /* 1. LOOP INVARIANT */
        for (int i = 1; i <= n; i++) {
            if (i % 2 != 0) {
                sum += i;
                count++;
            }
        }
        return sum / count;
}
