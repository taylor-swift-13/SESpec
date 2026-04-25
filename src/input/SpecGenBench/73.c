int foo73(int n);

int foo73(int n) {

        if(n <= 0) {
            return 0;
        }
        while (n % 4 == 0) {
            n /= 4;
        }
        return n == 1;
}
