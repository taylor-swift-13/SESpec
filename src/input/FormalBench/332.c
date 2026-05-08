int foo332(int n);

int foo332(int n) {

        int factorial = 1;
        for (int i = 1; i <= n; i++) {
            factorial *= i;
        }
        int foo332 = (int) (factorial % 100);
        return foo332;
}
