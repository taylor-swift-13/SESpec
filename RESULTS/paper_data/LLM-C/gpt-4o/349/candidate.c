/*@
    requires n > 0;
    ensures \result >= 0;
    ensures \result == \sum(1, n, (n % \lambda == 0 && \lambda % 2 != 0) ? \lambda : 0);
*/
int sumOfOddFactors(int n) {

        int sum = 0;
        /*@
            loop invariant 1 <= i <= n + 1;
            loop invariant sum == \sum(1, i - 1, (n % \lambda == 0 && \lambda % 2 != 0) ? \lambda : 0);
            loop assigns i, sum;
            loop variant n - i;
        */
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                if (i % 2 != 0) {
                    sum += i;
                }
            }
        }
        return sum;
}
