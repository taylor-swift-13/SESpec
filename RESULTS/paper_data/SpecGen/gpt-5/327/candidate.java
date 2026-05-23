class Sespec0327 {
    static int foo327(int n) {
        int fact = 1;
        for (int i = 2; i <= n; i++) {
            fact *= i;
        }
        int foo327 = 0;
        while (fact > 0) {
            foo327 = fact % 10;
            fact /= 10;
        }
        return foo327;
    }
}
