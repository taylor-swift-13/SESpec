int foo33(int n);

int foo33(int n) {

        if (n == 0) {
            return 3;
        }
        if (n == 1) {
            return 3;
        }
        if (n == 2) {
            return 5;
        }
        int sum = 5;
        int a = 3;
        int b = 0;
        int c = 2;
        while (n > 2) {
            int d = a + b;
            sum = sum + d;
            a = b;
            b = c;
            c = d;
            n--;
        }
        return sum;
}
