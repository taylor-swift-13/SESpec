int foo204(int n);

int foo204(int n) {

        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                if (i % 2 != 0) {
                    sum += i;
                }
            }
        }
        return sum;
}
