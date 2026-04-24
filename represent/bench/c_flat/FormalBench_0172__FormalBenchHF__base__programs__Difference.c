int difference(int n);

int difference(int n) {

        int sum = 0;
        int sum1 = 0;
        for (int i = 1; i <= n; i++) {
            sum += i * i * i;
        }
        for (int i = 1; i <= n; i++) {
            sum1 += i;
        }
        return sum - sum1;
}
