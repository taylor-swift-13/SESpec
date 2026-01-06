
/*@
    requires n >= 1 && n <= 1000;
*/
void foo262(int n) {
    int sum;
    int i;

    sum = 0;
    i = 0;

    /*@
        loop invariant sum == i * (i - 1) / 2;
        loop invariant 0 <= i <= n;
        loop invariant 2 * sum == i * (i - 1);
        loop invariant n == \at(n,Pre);
        loop assigns sum, i;
    */
    while (i < n) {
        sum = sum + i;
        i = i + 1;
    }

    /*@ assert 2 * sum == n * (n - 1); */
}
