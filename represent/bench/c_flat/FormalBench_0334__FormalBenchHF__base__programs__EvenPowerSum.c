int evenPowerSum(int n);

int evenPowerSum(int n) {

        int sum = 0;
        for (int i = 1; i <= n; i++) {
            int j = 2 * i;
            sum = sum + (j * j * j * j);
        }
        return sum;
}
