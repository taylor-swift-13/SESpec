#include <stdlib.h>

/*@ axiomatic WaysDef {
    logic integer ways(integer n, integer k, integer mod);

    axiom ways_base0: \forall integer k, mod; ways(0,k,mod) == 1;
    axiom ways_base1: \forall integer k, mod; ways(1,k,mod) == k;
    axiom ways_base2: \forall integer k, mod; ways(2,k,mod) == k*k;
    axiom ways_rec:
      \forall integer n, k, mod;
        n >= 3 ==> ways(n,k,mod) ==
          ((k-1) * (ways(n-1,k,mod) + ways(n-2,k,mod))) % mod;
  } */

/*@ requires n >= 2;
    requires 1 <= k <= 2;
    ensures \result == ways(n, k, 1000000007);
    ensures 0 <= \result < 1000000007;
*/
int countNoOfWays(int n, int k);

int countNoOfWays(int n, int k) {

        int mod = 1000000007;
        int *dp = (int *)malloc(sizeof(int) * (n+1));
/*@ assert dp != \null; */
/*@ assert \valid(dp + (0..n)); */
int dp_len = n+1;
        dp[0] = 1;
        dp[1] = k;
        dp[2] = k*k;
        /*@
          loop invariant \valid(dp + (0..n));
          loop invariant 3 <= i <= n ==> \true;
          loop invariant 3 <= i && i <= n ==> \forall integer j; 0 <= j < i ==> dp[j] == ways(j,k,mod);
          loop invariant 3 <= i && i <= n ==> \forall integer j; 3 <= j < i ==> 0 <= dp[j] < mod;
          loop assigns i, dp[3..n];
          loop variant n - i;
        */
        for(int i=3;i<=n;i++){
            dp[i] = ((k-1) * (dp[i-1] + dp[i-2])) % mod;
        }
/*@ assert dp[n] == ways(n,k,mod); */
        return dp[n];
}
