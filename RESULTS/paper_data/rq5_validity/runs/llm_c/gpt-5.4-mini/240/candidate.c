#include <stdlib.h>

/*@
    requires n >= 0;
    assigns \nothing;
    ensures \result == 0 || \result != 0;
*/
int evenBinomialCoeffSum(int n);

 /*@
    requires n >= 0;
    assigns \nothing;
    ensures \result == 0 || \result != 0;
*/
int evenBinomialCoeffSum(int n) {

        int sum = 0;
        int *dp = (int *)malloc(sizeof(int) * (n + 1));
int dp_len = n + 1;
        dp[0] = 1;
        /*@
            loop invariant 1 <= i <= n + 1;
            loop invariant dp[0] == 1;
            loop assigns i, j, dp[1..n];
            loop variant n - i + 1;
        */
        for (int i = 1; i <= n; i++) {
            /*@
                loop invariant 0 <= j <= i;
                loop assigns j, dp[i];
                loop variant i - j;
            */
            for (int j = 0; j < i; j++) {
                dp[i] = dp[i] + dp[j];
            }
        }
        return dp[n];
}
