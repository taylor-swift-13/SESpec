int nextPerfectSquare(int n);

/* 2. FUNC CONTRACT */
int nextPerfectSquare(int n) {

        int i = 1;
        int square = 1;
        /* 1. LOOP INVARIANT */
        while (square <= n) {
            square = i*i;
            i++;
        }
        return square;
}
