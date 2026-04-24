int isPowerOfTwo(int n);

int isPowerOfTwo(int n) {

        return n > 0 && (n & (n - 1)) == 0;
}
