#include <stdlib.h>

/*@ 
    logic integer JLP(integer k) =
        k == 0 ? 2
      : k == 1 ? 1
      : JLP(k-1) + 2 * JLP(k-2);

    requires n >= 1;
    assigns \nothing;
    ensures \result == JLP(n);
*/
int jacobsthalLucas(int n) {

        int *dp = (int *)malloc(sizeof(int) * (n + 1));
        int dp_len = n + 1;
        /*@ 
            // We require malloc to succeed for the function to behave correctly.
            // The following assertions are intended as local checks used by verification.
            @*/
        /*@ assert dp != \null; */
        /*@ assert \valid(dp + (0 .. n)); */

        dp[0] = 2;
        dp[1] = 1;
        /*@
            loop invariant 2 <= i <= n+1;
            loop invariant dp[0] == 2 && dp[1] == 1;
            loop invariant \forall integer k; 0 <= k < i ==> dp[k] == JLP(k);
            loop assigns i, dp[2 .. n];
            loop variant n - i + 1;
        */
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + 2 * dp[i - 2];
        }
        return dp[n];
}
