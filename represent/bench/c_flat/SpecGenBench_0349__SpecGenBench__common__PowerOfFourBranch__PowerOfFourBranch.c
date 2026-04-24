int isPowerOfFour(int n);

int isPowerOfFour(int n) {

        if(n <= 0) {
            return 0;
        }
        if((n & (n - 1)) != 0) {
            return 0;
        }
        if((n & 0xaaaaaaaa) != 0) {
            return 0;
        }
        return 1;
}
