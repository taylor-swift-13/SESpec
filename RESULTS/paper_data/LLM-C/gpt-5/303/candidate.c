#include <stdlib.h>

/*@ logic integer jacobsthal_lucas(integer k) =
      (k == 0 ? 2 : (k == 1 ? 1 : jacobsthal_lucas(k - 1) + 2 * jacobsthal_lucas(k - 2)));
*/

/*@ requires 1 <= n;
    assigns \nothing;
    ensures \result == jacobsthal_lucas(n);
*/
int jacobsthalLucas(int n);

int jacobsthalLucas(int n) {

/*@ ghost int dp_len = n + 1; */
        int *dp = (int *)malloc(sizeof(int) * (n + 1));
int dp_len = n + 1;
/*@ assert dp != \null; */
/*@ assert dp_len >= 2; */
/*@ assert \valid(dp + (0..dp_len-1)); */
        dp[0] = 2;
        dp[1] = 1;
        /*@ 
            loop invariant 2 <= i <= n + 1;
            loop invariant \valid(dp + (0..n));
            loop invariant \forall integer k; 0 <= k < i ==> dp[k] == jacobsthal_lucas(k);
            loop assigns i, dp[0..n];
            loop variant n - i + 1;
        */
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + 2 * dp[i - 2];
        }
        /*@ assert dp[n] == jacobsthal_lucas(n); */
        return dp[n];
}
