int averageOdd(int n);

int averageOdd(int n) {

        int sum = 0;
        int count = 0;
        /*@
        loop invariant 1 <= i <= n + 1;
        loop invariant 0 <= count <= i;
        loop invariant count * 2 <= i;
        loop invariant sum >= 0;
        loop invariant count == (i - 1) / 2 + (i % 2 != 0 ? 1 : 0);
        loop invariant count == (\numof integer k; 1 <= k < i && k % 2 != 0; 1);
        loop invariant sum == (\sum integer k; 1 <= k < i && k % 2 != 0; k);
        loop invariant sum == \sum(integer k = 1, k <= i - 1 && k % 2 != 0, k);
        loop invariant sum == \sum(integer k = 1, k < i, (k % 2 != 0) ? k : 0);
        loop invariant sum == \sum(integer k = 1, k < i && k % 2 != 0, k);
        loop invariant sum == \sum(integer k = 1, i-1, (k % 2 != 0) ? k : 0);
        loop invariant sum == (\sum integer k; 1 <= k <= i && k % 2 != 0; k);
        loop invariant sum == (\sum integer k; 1 <= k < i && k % 2 != 0; k);
        loop invariant sum % 2 == count % 2;
        loop invariant i == count + 1 || i == 2 * count;
        loop invariant i == 1 || i == count + 1 || i == 2 * count + 1;
        loop invariant i <= n+1;
        loop invariant i <= n + 1;
        loop invariant count == i / 2;
        loop invariant count == i / 2 || count == (i - 1) / 2;
        loop invariant count == \numof integer k; 1 <= k < i && k % 2 != 0; 1;
        loop invariant count == \floor(i / 2);
        loop invariant count == (i / 2) + (i % 2);
        loop invariant count == (i - 1) / 2;
        loop invariant count == (i - 1) / 2 || count == i / 2;
        loop invariant count == (i - 1) / 2 + (i % 2);
        loop invariant count == (i - 1) / 2 + (i % 2 == 0 ? 0 : 1);
        loop invariant count == (i - 1) / 2 + ((i - 1) % 2 != 0 ? 1 : 0);
        loop invariant count == (\numof integer k; 1 <= k < i && k % 2 != 0; 1);
        loop invariant count <= sum;
        loop invariant count <= i;
        loop invariant count <= (i + 1) / 2;
        loop invariant count * 2 <= i;
        loop invariant count * 2 <= i + 1;
        loop invariant \forall integer k; 1 <= k < i ==> (k % 2 == 0 || sum >= 0);
        loop invariant \forall integer k; 1 <= k < i ==> (k % 2 == 0 || count >= 0);
        loop invariant \forall integer k; 1 <= k < i ==> (k % 2 != 0 ==> sum >= k);
        loop invariant \forall integer k; 1 <= k < i && k % 2 != 0 ==> sum >= k;
        loop invariant \exists integer k; 1 <= k < i && k % 2 != 0 && count > 0 ==> sum >= count;
        loop invariant 1 <= i;
        loop invariant 1 <= i || i == 0;
        loop invariant 0 <= sum;
        loop invariant 0 <= i;
        loop invariant 0 <= count;
        loop assigns sum;
        loop assigns i;
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
