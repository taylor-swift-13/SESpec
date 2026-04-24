int firstDigit(int n);

int firstDigit(int n) {

        int fact = 1;
        for (int i = 2; i <= n; i++) {
            fact *= i;
        }
        int firstDigit = 0;
        while (fact > 0) {
            firstDigit = fact % 10;
            fact /= 10;
        }
        return firstDigit;
}
