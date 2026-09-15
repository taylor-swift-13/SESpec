int difference(int n);

int difference(int n) {

        int sum = 0;
        int sum1 = 0;
        /*@
        loop invariant 1 <= i <= n + 1;
        loop invariant sum == ((i - 1) * i / 2) * ((i - 1) * i / 2);
        loop assigns i;
        loop assigns sum;
        
        loop invariant 1 <= i <= n + 1;
        loop invariant sum1 == (i - 1) * i / 2;
        loop assigns i;
        loop assigns sum1;
        */
        for (int i = 1; i <= n; i++) {
            sum += i * i * i;
        }
        for (int i = 1; i <= n; i++) {
            sum1 += i;
        }
        return sum - sum1;
}
