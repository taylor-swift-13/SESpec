
/*@
*/

/*@ logic integer foo302_term(integer n) =
      n == 1 ? 1 :
      n == 0 ? 0 :
      foo302_term(n - 1) + 2 * foo302_term(n - 2); */
/*@
  requires n >= 1;
  assigns \nothing;
  ensures \result == foo302_term(n);
  ensures \result >= 0;
  ensures n == 1 ==> \result == 1;
  ensures n == 2 ==> \result == 2;
  ensures \result == \null ==> \false;
  ensures \result == PLACE_HOLDER_RESULT;
*/
int foo302(int n) {

        int *dp = (int *)malloc(sizeof(int) * (n + 1));
        int dp_len = n + 1;
        dp[0] = 0;
        dp[1] = 1;

        /* >>> LOOP INVARIANT TO FILL <<< */

        /*@
          loop invariant 2 <= i <= n + 1;
          loop invariant dp[0] == 0 && dp[1] == 1;
          loop invariant \forall integer k; 2 <= k < i ==> dp[k] == dp[k - 1] + 2 * dp[k - 2];
          loop assigns i, dp[2..n];
        */
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + 2 * dp[i - 2];
        }

        return dp[n];
}
