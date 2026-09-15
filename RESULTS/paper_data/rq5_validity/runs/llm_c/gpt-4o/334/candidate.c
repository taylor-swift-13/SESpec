/*@
    requires n >= 0;
    ensures \result == (\sum(1, n, \lambda integer i; i * i * i)) - (\sum(1, n, \lambda integer i; i));
    assigns \nothing;
*/
int difference(int n) {

        int sum = 0;
        int sum1 = 0;

        /*@
            loop invariant 1 <= i <= n + 1;
            loop invariant sum == \sum(1, i - 1, \lambda integer j; j * j * j);
            loop assigns i, sum;
            loop variant n - i;
        */
        for (int i = 1; i <= n; i++) {
            sum += i * i * i;
        }

        /*@
            loop invariant 1 <= i <= n + 1;
            loop invariant sum1 == \sum(1, i - 1, \lambda integer j; j);
            loop assigns i, sum1;
            loop variant n - i;
        */
        for (int i = 1; i <= n; i++) {
            sum1 += i;
        }

        return sum - sum1;
}
