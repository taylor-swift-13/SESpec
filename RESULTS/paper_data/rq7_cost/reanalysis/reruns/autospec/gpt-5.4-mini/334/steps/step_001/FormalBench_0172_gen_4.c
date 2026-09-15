int difference(int n);

int difference(int n) {

        int sum = 0;
        int sum1 = 0;
        /*@
        loop invariant 0 <= i <= n+1;
        loop invariant sum == \sum(integer k=1, i-1, k*k*k);
        loop assigns i;
        loop assigns sum;
        */
        for (int i = 1; i <= n; i++) {
            sum += i * i * i;
        }
        for (int i = 1; i <= n; i++) {
            sum1 += i;
        }
        return sum - sum1;
}
