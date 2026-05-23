import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountNoOfWays {

    /*@ 
      @ requires n >= 2 && k >= 0;
      @ ensures 0 <= \result && \result < 1000000007;
      @ ensures (\exists int[] dpSpec; dpSpec.length == n+1
      @          && dpSpec[0] == 1
      @          && dpSpec[1] == k
      @          && dpSpec[2] == (k * k) % 1000000007
      @          && (\forall int i; 3 <= i && i <= n;
      @                 dpSpec[i] == ((k-1) * (dpSpec[i-1] + dpSpec[i-2])) % 1000000007)
      @          && \result == dpSpec[n]);
      @*/
    public static int countNoOfWays(int n, int k) {
        int mod = 1000000007;
        int dp[] = new int[n+1];
        dp[0] = 1;
        dp[1] = k;
        dp[2] = k*k;
        /*@ 
          @ maintaining 3 <= i && i <= n+1;
          @ maintaining dp.length == n+1;
          @ maintaining dp[0] == 1 && dp[1] == k && dp[2] == (k*k) % mod;
          @ maintaining (\forall int j; 3 <= j && j < i;
          @                 dp[j] == ((k-1) * (dp[j-1] + dp[j-2])) % mod);
          @ decreases n - i + 1;
          @*/
        for(int i=3;i<=n;i++){
            dp[i] = ((k-1) * (dp[i-1] + dp[i-2])) % mod;
        }
        return dp[n];
    }
}