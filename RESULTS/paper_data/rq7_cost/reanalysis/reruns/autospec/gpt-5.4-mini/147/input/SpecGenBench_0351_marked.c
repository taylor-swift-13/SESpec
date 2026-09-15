int isPowerOfThree(int n);

/* 2. FUNC CONTRACT */
int isPowerOfThree(int n) {

        int temp = n;
        /* 1. LOOP INVARIANT */
        while (temp != 0 && temp % 3 == 0) {
            temp /= 3;
        }
        return temp == 1;
}
