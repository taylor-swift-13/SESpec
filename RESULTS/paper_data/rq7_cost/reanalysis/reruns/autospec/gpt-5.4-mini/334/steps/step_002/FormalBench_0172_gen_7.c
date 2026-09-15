int difference(int n);

int difference(int n) {

        int sum = 0;
        int sum1 = 0;
        /*@
        loop invariant sum1 == \sum(integer k) (1 <= k < i ==> k);
        loop invariant sum1 == \sum(integer k = 1; k < i; k++) k;
        loop invariant sum1 == (i-1)*i/2;
        loop invariant sum1 == (i - 1) * i / 2;
        loop invariant sum == \sum(integer k=1, i-1, k*k*k);
        loop invariant sum == \sum(integer k) (1 <= k < i ==> k * k * k);
        loop invariant sum == \sum(integer k = 1; k < i; k++) k * k * k;
        loop invariant sum == \sum(integer k = 1; k < i; k++) (k * k * k);
        loop invariant sum == (i-1)*i*(2*i-1)*(i-1)/4;
        loop invariant sum == ((i - 1) * i / 2) * ((i - 1) * i / 2);
        loop invariant i <= n+1;
        loop invariant i <= n + 1;
        loop invariant 1 <= i;
        loop invariant 0 <= i;
        loop assigns sum;
        loop assigns sum1;
        loop assigns i;
        */
        for (int i = 1; i <= n; i++) {
            sum += i * i * i;
        }
        /*@
        loop invariant 1 <= i <= n + 1;
        loop invariant sum == \sum(integer k = 1; k < i; k++) (k * k * k);
        loop invariant sum1 == \sum(integer k = 1; k < i; k++) k;
        loop invariant sum1 == (i - 1) * i / 2;
        loop invariant sum == ((i - 1) * i / 2) * ((i - 1) * i / 2);
        loop assigns sum;
        loop assigns sum1;
        loop assigns i;
        */
        for (int i = 1; i <= n; i++) {
            sum1 += i;
        }
        return sum - sum1;
}
