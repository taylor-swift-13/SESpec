int maxPrimeFactors(int n);

int maxPrimeFactors(int n) {

        int max = 0;
        for (int i = 2; i <= n; i++) {
            while (n % i == 0) {
                max = i;
                n /= i;
            }
        }
        return max;
}
