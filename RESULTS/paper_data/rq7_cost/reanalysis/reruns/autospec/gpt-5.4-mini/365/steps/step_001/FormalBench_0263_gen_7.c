int averageOdd(int n);

int averageOdd(int n) {

        int sum = 0;
        int count = 0;
        /*@
        loop invariant 0 <= count <= i;
        loop invariant 0 <= sum;
        loop invariant count == (i / 2) + (i % 2);
        loop invariant sum == (\sum integer k; 1 <= k <= i && k % 2 != 0; k);
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
