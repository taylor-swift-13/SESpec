#include <stdlib.h>

int jacobsthalNum(int n);

/*@ 
    logic integer J(integer k) = (k == 0 ? 0 : (k == 1 ? 1 : J(k-1) + 2 * J(k-2)));

    requires n >= 1;
    assigns \nothing;
    ensures \result == J(n);
*/
int jacobsthalNum(int n) {

        int *dp = (int *)malloc(sizeof(int) * (n + 1));
        int dp_len = n + 1;
        dp[0] = 0;
        dp[1] = 1;
        /*@
            loop invariant 2 <= i <= n+1;
            loop invariant \forall integer j; 0 <= j < i ==> dp[j] == J(j);
            loop assigns i, dp[0 .. n];
            loop variant n - i + 1;
        */
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + 2 * dp[i - 2];
        }
        return dp[n];
}
