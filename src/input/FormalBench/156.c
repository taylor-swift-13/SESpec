int foo156(int n);

int foo156(int n) {

        int fact = 1;
        for (int i = 2; i <= n; i++) {
            fact *= i;
        }
        int foo156 = 0;
        while (fact > 0) {
            foo156 = fact % 10;
            fact /= 10;
        }
        return foo156;
}
