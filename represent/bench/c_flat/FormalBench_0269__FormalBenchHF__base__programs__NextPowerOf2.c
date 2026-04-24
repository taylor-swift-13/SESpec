int nextPowerOf2(int n);

int nextPowerOf2(int n) {

        if (n == 0) {
            return 1;
        }
        int i = 1;
        while (i < n) {
            i = i << 1;
        }
        return i;
}
