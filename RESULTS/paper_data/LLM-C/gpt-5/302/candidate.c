#include <stdlib.h>

/*@ 
  axiomatic Jacobsthal {
    logic integer jbn(integer n) = 
      (n == 0 ? 0 : (n == 1 ? 1 : jbn(n-1) + 2 * jbn(n-2)));
  }
*/

/*@ 
  requires n >= 1;
  ensures \result == jbn(n);
*/
int jacobsthalNum(int n);

int jacobsthalNum(int n) {

/*@ 
  ensures \result == jbn(n);
*/
        int *dp = (int *)malloc(sizeof(int) * (n + 1));
/*@ 
  assume dp != \null;
  assume \valid(dp + (0 .. n));
*/
int dp_len = n + 1;
/*@ assert dp_len == n + 1; */
        dp[0] = 0;
        dp[1] = 1;
/*@ 
  loop invariant 2 <= i <= n + 1;
  loop invariant \valid(dp + (0 .. n));
  loop invariant dp[0] == 0 && dp[1] == 1;
  loop invariant \forall integer k; 0 <= k < i ==> dp[k] == jbn(k);
  loop assigns dp[2 .. n], i;
  loop variant n - i + 1;
*/
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + 2 * dp[i - 2];
        }
/*@ assert \forall integer k; 0 <= k <= n ==> dp[k] == jbn(k); */
/*@ assert dp[n] == jbn(n); */
        return dp[n];
}
