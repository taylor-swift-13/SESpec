int averageOdd(int n);

int averageOdd(int n) {

        int sum = 0;
        int count = 0;
        /*@
        loop invariant 0 <= i <= n + 1;
        loop invariant 0 <= count <= i;
        loop invariant sum >= 0;
        loop invariant count == (i - 1) / 2 + (i % 2);
        loop assigns i;
        loop assigns sum;
        loop assigns count;
        */
        for (int i = 1; i <= n; i++) {
            if (i % 2 != 0) {
                sum += i;
                count++;
            }
        }
        return sum / count;
}
