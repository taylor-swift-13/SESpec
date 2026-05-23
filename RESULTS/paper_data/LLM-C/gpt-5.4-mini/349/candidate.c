/*@
    requires n >= 0;
    assigns \nothing;
    ensures \result >= 0;
*/
int sumOfOddFactors(int n);

 /*@
    requires n >= 0;
    assigns \nothing;
    ensures \result >= 0;
*/
int sumOfOddFactors(int n) {

        int sum = 0;
        /*@
            loop invariant 1 <= i <= n + 1;
            loop invariant sum >= 0;
            loop invariant sum == \sum(integer k; 1 <= k < i && n % k == 0 && k % 2 != 0; k);
            loop assigns i, sum;
            loop variant n - i + 1;
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
