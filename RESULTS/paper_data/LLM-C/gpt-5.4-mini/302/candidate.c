#include <stdlib.h>

/*@
    requires n >= 1;
    requires \valid((int *)malloc(sizeof(int) * (n + 1)));
    assigns \nothing;
    ensures \result >= 0;
*/
int jacobsthalNum(int n);

int jacobsthalNum(int n) {

        int *dp = (int *)malloc(sizeof(int) * (n + 1));
int dp_len = n + 1;
        dp[0] = 0;
        dp[1] = 1;
        /*@
            loop invariant 2 <= i <= n + 1;
            loop invariant dp[0] == 0;
            loop invariant dp[1] == 1;
            loop invariant \forall integer j; 2 <= j < i ==> dp[j] == dp[j - 1] + 2 * dp[j - 2];
            loop assigns i, dp[2..n];
            loop variant n - i + 1;
        */
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + 2 * dp[i - 2];
        }
        return dp[n];
}
