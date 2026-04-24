int findNthDigit(int p, int q, int n);

int findNthDigit(int p, int q, int n) {

        int res = 0;
        while (n > 0) {
            n -= 1;
            p *= 10;
            res = p / q;
            p %= q;
        }
        return res;
}
