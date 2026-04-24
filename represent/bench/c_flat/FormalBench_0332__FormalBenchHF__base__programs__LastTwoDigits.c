int lastTwoDigits(int n);

int lastTwoDigits(int n) {

        int factorial = 1;
        for (int i = 1; i <= n; i++) {
            factorial *= i;
        }
        int lastTwoDigits = (int) (factorial % 100);
        return lastTwoDigits;
}
