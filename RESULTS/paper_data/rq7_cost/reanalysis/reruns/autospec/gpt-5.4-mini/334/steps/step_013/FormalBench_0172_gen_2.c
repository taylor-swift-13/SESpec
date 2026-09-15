int difference(int n);

int difference(int n) {

        int sum = 0;
        int sum1 = 0;
        /*@
        loop invariant 1 <= i <= n + 1;
        loop invariant 0 <= sum;
        loop invariant 0 <= sum1;
        loop invariant sum1 == (i - 1) * i / 2;
        loop invariant sum == (i - 1) * i * (2 * i - 1) * (3 * i * i - 3 * i - 1) / 30;
        loop invariant sum >= sum1;
        loop invariant sum - sum1 >= 0;
        loop invariant \forall integer k; 1 <= k < i ==> sum >= k * k * k;
        loop invariant \forall integer k; 1 <= k < i ==> sum1 >= k;
        loop invariant sum1 == i * (i - 1) / 2;
        loop invariant sum1 == \sum(integer k) (1 <= k < i ==> k);
        loop invariant sum1 == \sum(integer k = 1; k < i; k++) k;
        loop invariant sum1 == (i-1)*i/2;
        loop invariant sum1 == (i - 1) * i / 2;
        loop invariant sum1 <= sum;
        loop invariant sum1 <= i * i;
        loop invariant sum1 <= i * i || sum1 * sum1 <= sum;
        loop invariant sum1 < i * i;
        loop invariant sum1 * sum1 <= sum;
        loop invariant sum1 * sum1 < sum;
        loop invariant sum >= 0 && sum1 >= 0;
        loop invariant sum >= 0 && sum1 >= 0 && i >= 1;
        loop invariant sum == sum1 * sum1;
        loop invariant sum == sum1 * sum1 * sum1;
        loop invariant sum == sum1 * sum1 * sum1 || sum == sum1 * sum1;
        loop invariant sum == \sum(integer k=1, i-1, k*k*k);
        loop invariant sum == \sum(integer k) (1 <= k < i ==> k * k * k);
        loop invariant sum == \sum(integer k = 1; k < i; k++) k * k * k;
        loop invariant sum == \sum(integer k = 1; k < i; k++) (k * k * k);
        loop invariant sum == 0 || sum >= sum1;
        loop invariant sum == (i-1)*i*(2*i-1)*(i-1)/4;
        loop invariant sum == (i - 1) * i * (2 * i - 1) * (3 * i * i - 3 * i - 1) / 30;
        loop invariant sum == ((i - 1) * i / 2) * ((i - 1) * i / 2);
        loop invariant sum == ((i - 1) * i / 2) * ((i - 1) * i / 2) * ((i - 1) * i / 2);
        loop invariant i <= n+1;
        loop invariant i <= n + 1;
        loop invariant \forall integer k; 1 <= k < i ==> sum1 >= k;
        loop invariant \forall integer k; 1 <= k < i ==> sum >= k * k * k;
        loop invariant 1 <= i;
        loop invariant 0 <= sum;
        loop invariant 0 <= sum1;
        loop invariant 0 <= sum - sum1;
        loop invariant 0 <= sum && 0 <= sum1;
        loop invariant 0 <= i;
        loop assigns sum;
        loop assigns sum1;
        loop assigns i;
        */
        for (int i = 1; i <= n; i++) {
            sum += i * i * i;
        }
        /*@
        loop invariant sum1 == \sum(integer k = 1; k < i; k++) k;
        loop invariant sum1 == (i - 1) * i / 2;
        loop invariant sum1 <= sum;
        loop invariant sum1 <= i * (i - 1) / 2;
        loop invariant sum1 * sum1 <= sum;
        loop invariant sum >= 0 && sum1 >= 0;
        loop invariant sum == sum1 * sum1;
        loop invariant sum == \sum(integer k = 1; k < i; k++) (k * k * k);
        loop invariant sum == (i - 1) * i * (2 * i - 1) * (3 * i * i - 3 * i - 1) / 30;
        loop invariant sum == ((i - 1) * i / 2) * ((i - 1) * i / 2);
        loop invariant sum == ((i - 1) * i / 2) * ((i - 1) * i / 2) * ((i - 1) * i / 2);
        loop invariant i <= n + 1;
        loop invariant \forall integer k; 1 <= k < i ==> sum1 >= k;
        loop invariant \forall integer k; 1 <= k < i ==> sum1 >= 0;
        loop invariant \forall integer k; 1 <= k < i ==> sum >= k * k * k;
        loop invariant \forall integer k; 1 <= k < i ==> sum >= 0;
        loop invariant 1 <= i;
        loop invariant 0 <= sum;
        loop invariant 0 <= sum1;
        loop invariant 0 <= sum - sum1;
        loop invariant 0 <= sum && 0 <= sum1 && 0 <= i;
        loop invariant 0 <= i;
        loop assigns sum;
        loop assigns sum1;
        loop assigns i;
        */
        for (int i = 1; i <= n; i++) {
            sum1 += i;
        }
        return sum - sum1;
}
