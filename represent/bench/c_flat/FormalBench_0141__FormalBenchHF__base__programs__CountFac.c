int countFac(int n);

int countFac(int n) {

        int count = 0;
        if (n == 1) return 1;
        for (int i = 2; i <= n / i; i++) {
            if (n % i == 0) {
                count++;
                if (n / i == i) {
                    break;
                }
            }
        }
        return count;
}
