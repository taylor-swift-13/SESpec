int smallestDivisor(int n);

int smallestDivisor(int n) {

        int i = 2;
        while (i <= n / i) {
            if (n % i == 0) {
                return i;
            }
            i++;
        }
        return n;
}
