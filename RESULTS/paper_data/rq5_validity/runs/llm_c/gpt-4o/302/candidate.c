#include <stdlib.h>

/*@
    requires n >= 0;
    ensures \result == 0 ==> n == 0;
    ensures \result == 1 ==> n == 1;
    ensures n >= 2 ==> \result == jacobsthalNum(n-1) + 2 * jacobsthalNum(n-2);
    assigns \nothing;
*/
int jacobsthalNum(int n) {

    /*@
        requires n >= 0;
        ensures \valid(dp + (0..n));
        ensures dp[0] == 0;
        ensures dp[1] == 1;
        ensures \forall integer i; 2 <= i <= n ==> dp[i] == dp[i-1] + 2 * dp[i-2];
        assigns dp[0..n];
    */
    int *dp = (int *)malloc(sizeof(int) * (n + 1));
    int dp_len = n + 1;
    dp[0] = 0;
    dp[1] = 1;

    /*@
        loop invariant 2 <= i <= n + 1;
        loop invariant \forall integer j; 2 <= j < i ==> dp[j] == dp[j-1] + 2 * dp[j-2];
        loop assigns i, dp[2..n];
        loop variant n - i;
    */
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 2 * dp[i - 2];
    }

    int result = dp[n];
    free(dp);
    return result;
}
