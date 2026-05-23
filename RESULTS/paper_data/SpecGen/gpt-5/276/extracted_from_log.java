import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountNoOfWays {

    /*@ requires n >= 2;
      @ ensures true;
      @*/
    public static int countNoOfWays(int n, int k) {
        int mod = 1000000007;
        int dp[] = new int[n+1];
        dp[0] = 1;
        dp[1] = k;
        dp[2] = k*k;
        //@ maintaining 3 <= i && i <= n + 1;
        //@ maintaining dp != null && dp.length == n + 1;
        //@ decreases n - i + 1;
        for(int i=3;i<=n;i++){
            dp[i] = ((k-1) * (dp[i-1] + dp[i-2])) % mod;
        }
        return dp[n];
    }
}