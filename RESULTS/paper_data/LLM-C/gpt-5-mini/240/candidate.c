#include <stdlib.h>

/*@
    requires 0 <= n && n <= 30;
    assigns \nothing;
    ensures n == 0 ? \result == 1 : \result == (1 << (n-1));
*/
int evenBinomialCoeffSum(int n);

int evenBinomialCoeffSum(int n) {

        int sum = 0;
        int *dp = (int *)malloc(sizeof(int) * (n + 1));
        int dp_len = n + 1;
        /*@ assert dp != \null; */
        /*@ assert \valid(dp+(0..dp_len-1)); */
        /*@ assert \forall integer k; 1 <= k <= n ==> dp[k] == 0; */
        dp[0] = 1;
        /*@
            loop invariant 1 <= i <= n+1;
            loop invariant dp[0] == 1;
            loop invariant \forall integer k; 1 <= k < i ==> dp[k] == (1 << (k-1));
            loop invariant \forall integer k; i <= k <= n ==> dp[k] == 0;
            loop assigns i, dp[1..n];
            loop variant n - i + 1;
        */
        for (int i = 1; i <= n; i++) {
            /*@
                loop invariant 0 <= j <= i;
                loop invariant dp[i] == \sum integer k; 0 <= k < j; dp[k];
                loop assigns j, dp[i];
                loop variant i - j;
            */
            for (int j = 0; j < i; j++) {
                dp[i] = dp[i] + dp[j];
            }
        }
        return dp[n];
}
