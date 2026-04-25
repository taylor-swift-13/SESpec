int foo72(int n);

int foo72(int n) {

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
